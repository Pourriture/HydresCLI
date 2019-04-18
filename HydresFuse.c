#include "HydresFuse.h"

field* fieldFuse(const field* source, const field* aColler, int pos_x, int pos_y)
{

    field* resultat = NULL;
    resultat = fieldCopy(source);
    int source_sx = source->fsize_x, source_sy = source->fsize_y, limcut_x = pos_x + aColler->fsize_x, limcut_y = pos_y + aColler->fsize_y;

    if ((limcut_x > source_sx) || (limcut_y > source_sy))
    {
        printf("Error fusing fields: pasted element is misplaced or too big for the target (x %d > sx %d or y %d > sy %d)\n",limcut_x,source_sx,limcut_y,source_sy);
        return resultat;
    }

    int i, j, ib, jb;

    for (i = 0, ib = pos_x ; ib < limcut_x ; i++, ib++)
    {
        for (j = 0, jb = pos_y ; jb < limcut_y ; j++, jb++)
        {
            resultat->fbody[ib][jb].caractere = aColler->fbody[i][j].caractere;
            resultat->fbody[ib][jb].color = aColler->fbody[i][j].color;
        }
    }



    return resultat;
}
