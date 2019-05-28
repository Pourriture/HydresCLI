#include "HydresString.h"

void fsPaste(field* terrain, char* chaine, int x, int y, int color)
{
    if (!terrain)
    {
        HydresErr(err_strpaste_nosource);
        return;
    }

    int i;
    for(i = 0 ; chaine[i] != '\0' ; i++)
    {
        if (x+i >= terrain->fsize_x)
        {
            break;
        }

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
    char* resultat = NULL;
    if (!terrain)
    {
        resultat = malloc(sizeof(char));
        if (resultat)
            *resultat = '\0';
        else
            herr.x = 1;
        HydresErr(err_strextract_nosource);
        return resultat;
    }

    resultat = malloc(sizeof(char) * (length + 1));
    if (!resultat)
    {
        HydresErr(err_misc_oom);
    }
    int i;
    for (i = 0 ; i < length ; i++)
    {
        resultat[i] = terrain->fbody[x + i][y].caractere;
    }
    resultat[length] = '\0';

    return resultat;
}
