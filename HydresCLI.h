#ifndef HYDRESCLI_H_INCLUDED
#define HYDRESCLI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct f_part f_part;
typedef struct field field;
#define DEFAULT_F_PART_CHAR 'I'
#define DEFAULT_F_PART_COLOR 2

#define DEBUG
/**
HYDRES COMMAND LINE INTERFACE - INTERFACE AVEC LA CONSOLE WINDOWS


field* fieldInitialize(int x, int y);
renvoie un pointeur vers un écran (field),
lui attribue une taille et une existence, puis l'initialise.
La constante d'initialisation est défine par DEFAULT_F_PART_CHAR et DEFAULT_F_PART_COLOR.

void fieldDestruction(*field);
Une fois l'écran utilisé, il faut le détruire pour libérer l'espace qu'il prenait en mémoire.
fieldDestruction ne prend qu'un seul argument : un pointeur vers l'écran à détruire.

void fieldDisplay(field*);
Affiche un écran entier (stdout).

field* fieldCopy(field* source);

field* fieldReInitialize(field* terrain, int size_x, int size_y);
*/


field* fieldInitialize(const int x, const int y);
void fieldDestroy(field*);
void fieldDisplay(const field*);
field* fieldCopy(const field* source);
//field* fieldReInitialize(field* terrain, const int size_x, const int size_y);

//partie d'un field : comporte le caractère et sa couleur
struct f_part
{
    char caractere;
    short int color;
};


//champ de caractères : pointe vers un tableau bidimensionnel de f_part
struct field
{
    int fsize_x;
    int fsize_y;
    f_part **fbody;


};

#endif // LCONSOLE_H_INCLUDED
