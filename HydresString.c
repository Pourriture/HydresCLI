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
