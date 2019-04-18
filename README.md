HYDRES COMMAND LINE INTERFACE - INTERFACE AVEC LA CONSOLE WINDOWS

Ceci est une documentation brève et incomplète.


void fieldInitialize(field*, int x, int y);
prend comme paramètres un pointeur vers un écran (field),
lui attribue une taille et une existence, puis l'initialise.
La constante d'initialisation est défine par DEFAULT_F_PART_CHAR et DEFAULT_F_PART_COLOR.
en pratique, beaucoup de fonctions initialisent automatiquement un écran avant de le modifier et de le rencoyer

void fieldDestruction(field*);
Une fois l'écran utilisé, il faut le détruire pour libérer l'espace qu'il prenait en mémoire.
fieldDestruction ne prend qu'un seul argument : un pointeur vers l'écran à détruire.

void fieldDisplay(field*);
Affiche un écran entier (stdout).

field* fieldCopy(field* source);
Cette fonction copie le contenu de la source dans un nouvel écran, qui lui est identique. Cet écran est initialisé
par la focntion, et devra donc être détruit avec fieldDestroy.

field* fieldReInitialize(field*, int size_x, int size_y);
fonction peu utilisable. réinitialise un écran déjà initialisé, lui attribuant une nouvelle taille.


HYDRESFILE:

field* fieldFromFile(const char*);
Cette fonction renvoie un écran créé depuis un fichier, dont le nom complet doit constituer le paramètre.
Ce fichier texte doit être correctement formaté.
L'écran doit être détruit après utilisation.

void fieldToFile(const char*, const field*);
Cette fonction écrit un fichier en mémoire contenant un écran, formaté correctement.

HYDRESFUSE:

field* fieldFuse(const field* source, const field* aColler, int pos_x, int pos_y);
Cette fonction renvoie un écran fusionné depuis une source (la source) et un élément à coller (pas la source)
à partir des coordonnées pos_x et pos_y de la source.
L'écran doit être détruit après utilisation.
