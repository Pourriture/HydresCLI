#ifndef HYDRESSTRING_H_INCLUDED
#define HYDRESSTRING_H_INCLUDED
#include "HydresCLI.h"
#include <string.h>



/** fsPaste colle la chaîne fournie (se finissant par '\0') sur l'écran envoyé en argument. */
void fsPaste(field*, char*, int x, int y, int color);
/** fsFuse renvoie une copie de l'écran envoyé en argument auquel on a collé la chaîne fournie (se finissant par '\0'). */
field* fsFuse(field*, char*, int x, int y, int color);

/** stringExtract renvoie une chaîne faîte de len caractères situées sur la ligne x et commençant dans la colomne y.  */
char* stringExtract(const field*, int x, int y, int len);

#endif // HYDRESSTRING_H_INCLUDED
