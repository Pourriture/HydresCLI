#ifndef HYDRESSTRING_H_INCLUDED
#define HYDRESSTRING_H_INCLUDED
#include "HydresCLI.h"
#include <string.h>

void fsPaste(field*, char*, int x, int y, int color);
field* fsFuse(field*, char*, int x, int y, int color);

char* stringExtract(const field*, int x, int y, int length);

#endif // HYDRESSTRING_H_INCLUDED
