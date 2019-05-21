#include "HydresFuse.h"

field* fieldFuse(const field* source, const field* aColler, const int pos_x, const int pos_y)
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


field* fieldFuseST(const field* source, const field* aColler, const int pos_x, const int pos_y)
{

    field* resultat = NULL;
    resultat = fieldCopy(source);
    int source_sx = source->fsize_x, source_sy = source->fsize_y, limcut_x = pos_x + aColler->fsize_x, limcut_y = pos_y + aColler->fsize_y;

    if ((limcut_x > source_sx) || (limcut_y > source_sy))
    {
        printf("Error STfusing fields: pasted element is misplaced or too big for the target (x %d > sx %d or y %d > sy %d)\n",limcut_x,source_sx,limcut_y,source_sy);
        return resultat;
    }

    int i, j, ib, jb;

    for (i = 0, ib = pos_x ; ib < limcut_x ; i++, ib++)
    {
        for (j = 0, jb = pos_y ; jb < limcut_y ; j++, jb++)
        {
            if (aColler->fbody[i][j].caractere != ' ')
            {
                resultat->fbody[ib][jb].caractere = aColler->fbody[i][j].caractere;
                resultat->fbody[ib][jb].color = aColler->fbody[i][j].color;
            }

        }
    }



    return resultat;
}

field* fieldAppendX(const field* sc1, const field* sc2)
{
    field* fuseSource = fieldInitialize(sc1->fsize_x + sc2->fsize_x,((sc1->fsize_y >= sc2->fsize_y) * sc1->fsize_y) + ((sc1->fsize_y < sc2->fsize_y) * sc2->fsize_y));
    field* fuseT1 = fieldFuse(fuseSource, sc1, 0, 0);
    field* resultat = fieldFuse(fuseT1, sc2, sc1->fsize_x, 0);
    fieldDestroy(fuseSource);
    fieldDestroy(fuseT1);
    return resultat;
}

field* fieldAppendY(const field* sc1, const field* sc2)
{
    field* fuseSource = fieldInitialize(((sc1->fsize_x >= sc2->fsize_x) * sc1->fsize_x) + ((sc1->fsize_x < sc2->fsize_x) * sc2->fsize_x),sc1->fsize_y + sc2->fsize_y);
    field* fuseT1 = fieldFuse(fuseSource, sc1, 0, 0);
    field* resultat = fieldFuse(fuseT1, sc2, 0, sc1->fsize_y);
    fieldDestroy(fuseSource);
    fieldDestroy(fuseT1);
    return resultat;
}

field* fieldAppend(const field* sc1, const field* sc2, const char choix)
{
    field* resultat = NULL;
    if ((choix == 'X') || (choix == 'x'))       // note : APPEND_HORIZONTAL == 'X'
    {
        resultat = fieldAppendX(sc1, sc2);
    }
    else
    {
        resultat = fieldAppendY(sc1, sc2);
    }
    return resultat;
}
