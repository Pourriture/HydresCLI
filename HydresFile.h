#ifndef HYDRESFILE_H_INCLUDED
#define HYDRESFILE_H_INCLUDED
#include "HydresCLI.h"
#include <string.h>


/** renvoie l'écran stocké dans le fichier du nom donné en paramètre */
field* fieldFromFile(const char*);

/** sauvegarde l'écran dans le fichier au nom donné en paramètre ; pour le troisième paramètre, vous pouvez indiquer DEFAULT_F_PART_COLOR */
void fieldToFile(const char*, const field*, const int);

/** sauvegarde en couleur l'écran au nom donné en paramètre */
void fieldCToFile(const char*, const field*);


#endif // HYDRESFILE_H_INCLUDED
