#include "HydresColor.h"


void fieldPaint(field* terrain, const int color)
{
    fieldPaintPart(terrain, color, 0, terrain->fsize_x - 1, 0, terrain->fsize_y - 1);
}

field* fieldCPaint(const field* terrain, const int color)
{
    field* resultat = fieldCopy(terrain);
    fieldPaint(resultat, color);
    return resultat;
}

void fieldPaintPart(field* terrain, const int color, const int s_x, const int e_x, const int s_y, const int e_y)
{
    if (!terrain)
    {
        HydresErr(err_paint_nosource);
        return;
    }
    if ((s_x < 0) || (s_y < 0) || (e_x >= terrain->fsize_x) || (e_y >= terrain->fsize_y))
    {
        herr.t[0] = s_x;
        herr.t[1] = s_y;
        herr.t[2] = e_x;
        herr.t[3] = e_y;
        herr.x = terrain->fsize_x;
        herr.y = terrain->fsize_y;
        HydresErr(err_paint_miscall);
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

field* fieldCPaintPart(const field* source, const int color, const int s_x, const int e_x, const int s_y, const int e_y)
{
    field* resultat = fieldCopy(source);
    fieldPaintPart(resultat, color, s_x, e_x, s_y, e_y);
    return resultat;
}
