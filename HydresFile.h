#ifndef HYDRESFILE_H_INCLUDED
#define HYDRESFILE_H_INCLUDED
#include "HydresCLI.h"
#include <string.h>


/** renvoie l'�cran stock� dans le fichier du nom donn� en param�tre */
field* fieldFromFile(const char*);

/** sauvegarde l'�cran dans le fichier au nom donn� en param�tre ; pour le troisi�me param�tre, vous pouvez indiquer DEFAULT_F_PART_COLOR */
void fieldToFile(const char*, const field*, const int);

/** sauvegarde en couleur l'�cran au nom donn� en param�tre */
void fieldCToFile(const char*, const field*);


#endif // HYDRESFILE_H_INCLUDED
