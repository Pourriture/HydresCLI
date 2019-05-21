#include "HydresString.h"

void fsPaste(field* terrain, char* chaine, int x, int y, int color)
{
    int i;
    for(i = 0 ; chaine[i] != '\0' ; i++)
    {
        terrain->fbody[x+i][y].caractere = chaine[i];
        terrain->fbody[x+i][y].color = color;
    }

}

field* fsFuse(field* source, char* chaine, int x, int y, int color)
{
    field* resultat = fieldCopy(source);
    fsPaste(resultat, chaine, x, y, color);
    return resultat;
}

char* stringExtract(const field* terrain, int x, int y, int length)
{
    char* resultat = malloc(sizeof(char) * (length + 1));
    int i;
    for (i = 0 ; i < length ; i++)
    {
        resultat[i] = terrain->fbody[x + i][y].caractere;
    }
    resultat[length] = '\0';

    return resultat;
}
