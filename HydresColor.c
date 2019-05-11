#include "HydresColor.h"


void fieldPaint(field* terrain, const int color)
{
    /*
    int size_x = terrain->fsize_x, size_y = terrain->fsize_y, i, j;
    for (i = 0 ; i < size_x ; i++)
    {
        for (j = 0 ; j < size_y ; j++)
        {
            terrain->fbody[i][j].color = color;
        }
    }
    */
    fieldPaintPart(terrain, color, 0, terrain->fsize_x, 0, terrain->fsize_y);
}

field* fieldCPaint(const field* terrain, const int color)
{
    field* resultat = fieldCopy(terrain);
    fieldPaint(resultat, color);
    return resultat;
}

void fieldPaintPart(field* terrain, const int color, const int s_x, const int e_x, const int s_y, const int e_y)
{
    if ((s_x < 0) || (s_y < 0) || (e_x >= terrain->fsize_x) || (e_y >= terrain->fsize_y))
    {
        fprintf(stdout,"Error: fieldACDisplay miscalled, either:\n");
        fprintf(stdout,"s_x %d < 0\n",s_x);
        fprintf(stdout,"s_y %d < 0\n",s_y);
        fprintf(stdout,"e_x %d >= terrain->fsize_x %d\n",e_x,terrain->fsize_x);
        fprintf(stdout,"e_y %d >= terrain->fsize_y %d\n",e_y,terrain->fsize_y);
        return;
    }
    int i, j;

    for (i = s_x ; i <= e_x ; i++)
    {
        for (j = s_y ; j <= e_y ; j++)
        {
            terrain->fbody[i][j].color = color;
        }
    }
}
