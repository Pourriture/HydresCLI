#ifndef HYDRESCLI_H_INCLUDED
#define HYDRESCLI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "HydresErr.h"
typedef struct f_part f_part;
typedef struct field field;
#define DEFAULT_F_PART_CHAR 'I'
#define DEFAULT_F_PART_COLOR 2

#define DEBUG

/** Renvoie un pointeur vers un écran (field), lui attribue une taille et un tableau bidimensionnel.
la constante d'initialisation de chacune des cellules est défine par DEFAULT_F_PART_CHAR et DEFAULT_F_PART_COLOR. */
field* fieldInitialize(const int x, const int y);

/** Une fois l'écran utilisé, il faut le détruire pour libérer l'espace qu'il prenait en mémoire. Cette fonction détruit l'écran fourni en argument. */
void fieldDestroy(field*);


/** Affiche un écran entier sur stdout */
void fieldDisplay(const field*);

/** Renvoie une copie de l'écran envoyé en argument */
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
