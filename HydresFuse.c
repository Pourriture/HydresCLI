#include "HydresFuse.h"

field* fieldFuse(const field* source, const field* aColler, const int pos_x, const int pos_y)
{
    if (!source || !aColler)
    {

        if (!source)
            herr.x |= 1;
        if (!aColler)
            herr.x |= 2;
        HydresErr(err_fuse_nosource);
    }


    field* resultat = NULL;
    resultat = fieldCopy(source);
    int source_sx = source->fsize_x, source_sy = source->fsize_y, limcut_x = pos_x + aColler->fsize_x, limcut_y = pos_y + aColler->fsize_y;

    if ((limcut_x > source_sx) || (limcut_y > source_sy))
    {
        herr.t[0] = limcut_x;
        herr.t[1] = source_sx;
        herr.t[2] = limcut_y;
        herr.t[3] = source_sy;
        herr.err = errtag_sfuse;
        HydresErr(err_fuse_size);
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
    if (!source || !aColler)
    {
        herr.x |= 4;
        if (!source)
            herr.x |= 1;
        if (!aColler)
            herr.x |= 2;
        HydresErr(err_fuse_nosource);
    }


    field* resultat = NULL;
    resultat = fieldCopy(source);
    int source_sx = source->fsize_x, source_sy = source->fsize_y, limcut_x = pos_x + aColler->fsize_x, limcut_y = pos_y + aColler->fsize_y;

    if ((limcut_x > source_sx) || (limcut_y > source_sy))
    {
        herr.t[0] = limcut_x;
        herr.t[1] = source_sx;
        herr.t[2] = limcut_y;
        herr.t[3] = source_sy;
        herr.err = errtag_stfuse;
        HydresErr(err_fuse_size);
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
    if (!sc1 || !sc2)
    {
        herr.x |= ((!sc1)*1 + (!sc2)*2);
        HydresErr(err_append_nosource);
    }


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
