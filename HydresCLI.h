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
renvoie un pointeur vers un �cran (field),
lui attribue une taille et une existence, puis l'initialise.
La constante d'initialisation est d�fine par DEFAULT_F_PART_CHAR et DEFAULT_F_PART_COLOR.

void fieldDestruction(*field);
Une fois l'�cran utilis�, il faut le d�truire pour lib�rer l'espace qu'il prenait en m�moire.
fieldDestruction ne prend qu'un seul argument : un pointeur vers l'�cran � d�truire.

void fieldDisplay(field*);
Affiche un �cran entier (stdout).

field* fieldCopy(field* source);

field* fieldReInitialize(field* terrain, int size_x, int size_y);
*/


field* fieldInitialize(const int x, const int y);
void fieldDestroy(field*);
void fieldDisplay(const field*);
field* fieldCopy(const field* source);
//field* fieldReInitialize(field* terrain, const int size_x, const int size_y);

//partie d'un field : comporte le caract�re et sa couleur
struct f_part
{
    char caractere;
    short int color;
};


//champ de caract�res : pointe vers un tableau bidimensionnel de f_part
struct field
{
    int fsize_x;
    int fsize_y;
    f_part **fbody;


};

#endif // LCONSOLE_H_INCLUDED
