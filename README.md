DOCUMENTATION POUR L'INTERFACE AVEC LA CONSOLE WINDOWS HYDRES


Fichier principal : HydresCLI

But : HydresCLI est la brique de base du fonctionnement de Hydres. Les fonctions présentes dans HydresCLI.h et HydresCLI.c sont les plus basiques, et sont capitales au fonctionnement de toutes les autres fonctions de Hydres. En particulier, HydresCLI définit de quoi est fait un écran, comment est-il créé, comment peut-on interagir de manière simple avec lui, et comment peut-on le supprimer.



Structures :

f_part			//	cellule d'un écran  
{  
	char caractere;  
	int color;  
}  
On ne peut se contenter d'un char car on ne pourrait pas alors conserver de manière précise la couleur d'un caractère.



field			//	écran lui-même  
{  
	int fsize_x;  
	int fsize_y;  
	fpart **f_body;  
}  
.fsize_x et .fsize_y permettent de conserver en mémoire la hauteur et la largeur d'un écran. Il ne faut jamais éditer ces données !  
Conserver la hauteur et la largeur d'un écran dans la variable même est utile pour faciliter le fonctionnement de fonctions assemblant des écrans ensemble, ou leur appliquant de la couleur, ou simplement les affichant.  

.fbody est en fait un pointeur vers un tableau bidimensionnel de cellules d'écran. Il est utilisable comme tableau à deux dimensions : par exemple, on pourrait faire ecran.fbody[2][3].caractere = 'A'. Dans les faits, on travaillera surtout avec des pointeurs vers des écrans dynamiquement alloués, afin de ne plus avoir à se soucier de ce qui est détruit à la fin de la fonction, et sutout de pouvoir rapidement et facilement initialiser un écran.


Fonctions :

Pour initialiser un écran, on utilisera la fonction : 

field* fieldInitialize(const int size_x, const int size_y);

(pour rappel, le mot-clef const avant le type d'une variable dans le prototype d'une fonction signifie que la variable ne sera pas modifiée durant le fonctionnement de la fonction)


Cette fonction allouera un espace dédié à un écran, lui inscrira en mémoire sa hauteur et sa largeur, et renverra un pointeur vers cet écran. Par exemple, field* ecran = fieldInitalize(4, 5) intialise un écran de largeur 4 et de hauteur 5.  
L'écran sera initialisé suivant les constantes de précompilateur inscrites dans le fichier HydresCLI.h. Ces constantes sont définies au début du fichier HydresCLI.h :

#define DEFAULT_F_PART_CHAR 'I'

#define DEFAULT_F_PART_COLOR 2


On notera que DEFAULT_F_PART_COLOR est ici un nombre. Ce nombre correspond à "couleur du texte : vert" pour Windows ; pour plus de détails, veuillez consulter la partie de la documentation relative à HydresColor.h.  
Une fois un écran créé, il faut toujours le supprimer manuellement. Ne pas le supprimer expose le programme à des fuites de mémoire.  
On supprimera un écran initialisé en appelant simplement la fonction fieldDestroy :

void fieldDestroy(field*);  

Le seul argument est l'écran à supprimer.  

fieldDestroy fonctionne en libérant méthodiquement tout l'espace alloué à l'écran, en particulier son tableau bidimensionnel.

On peut aussi créer une copie d'un écran, avec la fonction fieldCopy, qui renvoie la copie :  
field* fieldCopy(const field* source);  

Cette fonction permet d'obtenir une copie d'un écran existant. Il ne faut l'utiliser que sur un pointeur qui n'a pas déjà d'écran assigné, car elle ne supprimerait pas l'écran associé à un pointeur déjà assigné ; si on faisait cela, on obtiendrait une fuite de mémoire. Exemple explicatif :  

field* ecran1 = fieldInitialize(5, 5);  
field* ecran2 = fieldInitialize(10, 10);  

Ici, on vient de créer deux écrans ecran1 et ecran2. On peut y accéder grâce aux pointeurs qui contiennent leurs adresses. Disons que ecran1 pointe vers l'adresse 13 et ecran2 vers l'adresse 58.  

On souhaite obtenir une copie d'ecran1.  
Si l'on effectuait l'opération  

ecran2 = fieldCopy(ecran1);  

ecran2 pointerait bel est bien vers une copie d'écran1, un tout nouvel écran situé disons à l'adresse 77... mais on a perdu du même coup l'accès à l'écran situé à l'adresse 58 ! Pour obtenir une copie d'ecran1, il faudrait donc faire soit :  

fieldDestroy(ecran2);			//il n'y a plus d'écran à l'adresse 58  
ecran2 = fieldCopy(ecran1)		//donc on peut donner un autre écran à ecran2  

soit :  

ecran3 = fieldCopy(ecran1)  

Vous noterez qu'on n'a pas besoin d'initialiser ecran3 avec fieldInitialize lorsqu'on procède ainsi ! C'est parce que fieldCopy appelle fieldInitialize lors de son fonctionnement. La plupart des fonctions renvoyant un field* procèdent ainsi. Pour cette raison, on se servira peu de fieldInitialize ; mais il est toujours bon de savoir qu'elle existe et à quoi elle sert.  
Lors de la copie, fieldCopy copie simplement un par un les attributs de chaque cellule de l'écran source dans un écran résultat qu'elle renvoie.  

La dernière fonction présente dans les fichiers HydresCLI.h et HydresCLI.c est fieldDisplay. Elle permet d'afficher simplement un écran entier, sans couleurs.  

void fieldDisplay(const field*)  

Le caractère dans chaque cellule est envoyé sur la console, sans formattage.  

Code exemple :  

int main()  
{  
	field* ecran = fieldInitialize(5,5);  
	field* ecran2 = fieldCopy(ecran);  
	ecran2->fbody[2][2].caractere = 'O';  
	fieldDisplay(ecran);  
	fieldDisplay(ecran2);  
	fieldDestroy(ecran);  
	fieldDestroy(ecran2);  
	return 0;  
}  



Fichier : HydresFile

But : HydresFile permet de sauvegarder un écran dans un fichier (une seule couleur), et de récupérer un écran depuis en fichier (une seule couleur).  


Fonctions :  

void fieldToFile(const char* nom_du_fichier, field*);

fieldToFile sauvegarde un écran entier dans un fichier. Le fichier est créé si il n'existe pas, et écrasé sinon.

Le format est le suivant :

(entier représentant la largeur) (entier représentant la hauteur) (code couleur)  
c  
  a     a  
     r   c  
  t    e     r  
 e   s   c  o  
m  p    o   s  
 a   n   t  
l e c r a n  
    

field* fieldFromFile(const char* nom_du_fichier)  
fieldFromFile initialise un écran et le modifie selon un fichier. L'écran devra être supprimé avec fieldDestroy.  
La fonction utilise le même format que fieldToFile.  



Fichier: HydresFuse

But : Permettre de coller un écran dans un autre écran plus grand ou d'apposer deux écrans l'un contre l'autre.

field* fieldFuse(const field* source, const* field aColler, const int posx, const int posy);  
field* fieldFuseST(const field* source, const* field aColler, const int posx, const int posy);  

fieldFuse prend deux écrans, la source et l'élément à coller. Les paramètres entiers posx et posy servent à déterminer la position de départ de la fusion (l'élément aColler sera collé à la source à partir des coordonnées (posx ; posy). L'élément à coller doit être plus petit que la source et ne doit pas dépasser des bords  
fieldFuse colle le caractère et la couleur de tous les éléments de aColler dans leur nouvelle position sur une copie de l'écran source, puis renvoie ce nouvel écran (qui doit donc être supprimé après utilisation).  
fieldFuseST fait de même, mais ne copie pas les espaces.  

field* fieldAppendX(const field* left, const field* right);  
fieldAppendX prend comme arguments deux écrans, et renvoie leur fusion l'un contre l'autre, de gauche à droite.   
L'écran renvoyé doit être détruit après utilisation.  
Si les tailles ne correspondent pas, les caractères "vides" sous le moins haut des deux sont remplacés par le caractère par défaut.  

field* fieldAppendY(const field* up, const field* down);  
Cette fonction fonctionne de la même manière, mais assemble les éléments de haut en bas. Les caractères "vides" à droite du moins large des deux sont remplacés par le caractère par défaut.  

field* fieldAppend(const field*, const field*, const char);  
Cette fonction appelle fieldAppendX ou fieldAppendY selon si le troisième paramètre contient x, X, y, ou Y.


Fichier : HydresColor

But : Gérer les couleurs d'un écran

void fieldPaintPart(field*, const int color, const int s_x, const int e_x, const int s_y, const int e_y);  
Cette fonction change la couleur de chaque caractère d'un écran donné entre le rectangle fourni par les coordonnées (s_x ; s_y) et (e_x ; e_y). Elle ne renvoie pas de copie.

void fieldPaint(field*, const int color);  
Cette fonction utilise fieldPaintPart() et les caractéristiques de l'écran fourni pour changer la couleur de toutes les cellules d'un écran. Elle ne renvoie pas de copie.  

field* fieldCPaint(const field*, const int color)  
Cette fonction renvoie une copie de l'écran fourni, entièrement coloré. Cette copie doit être détruite après utilisation.  

field* fieldCPaintPart(const field*, const int color, const int s_x, const int e_x, const int s_y, const int e_y);  
Cette fonction renvoie une copie de l'écran fourni, coloré dans le rectangle indiqué par (s_x ; s_y) et (e_x ; e_y).  


Fichier : HydresAdvDisplay  
But : Permettre une approche plus poussée de l'affichage : en couleurs, ou uniquement une partie d'un écran.  

void fieldCDisplay(const field*, const int s_posx, const int e_posx, const int s_posy, const int e_posy);  
Cut Display (only between s_posx and e_posy, colorstripped)  

void fieldADisplay(const field*);  
All-Display (with color !)  

void fieldACDisplay(const field*, const int s_posx, const int e_posx, const int s_posy, const int e_posy);  
All and Cut Display (between s_posx and e_posx, with color)  
