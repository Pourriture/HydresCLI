#ifndef HYDRESERR_H_INCLUDED
#define HYDRESERR_H_INCLUDED

#ifndef HYDRESCLI_H_INCLUDED // what to include for HydresErr.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <string.h>
#endif
#include "HydresSettings.h"



/** Renvoie le numéro de la dernière erreur Hydres (0 si aucune erreur ne s'est produite) */
int HydresErrNo();

/** Fonction à usage interne : inscrit les erreurs Hydres dans le stream errstream au fur et à mesure qu'elles se produisent */
void HydresErr(int no);

/** Utilisez cette fonction si vous avez défini un nouveau stream pour les erreurs */
void initErrStream();



#define SIZE_HERR_T 5
struct {
    int err;
    int x, y;
    int t[SIZE_HERR_T];
} herr;


#define DEFAULT_ERR_MESS "\nHydres version - Compiled at __DATE__ __TIME__\nError report:\n"
#define S_ERR                                   1
#define err_fieldInitialize_OutOfMemory         2
#define err_fieldInitialize_Misc                3
#define err_fieldDestroy                        4
#define err_copy_no_source                      5
#define err_display_no_source                   6
#define err_fuse_size                           7
#define err_fuse_nosource                       8
#define err_append_nosource                     9
#define err_paint_nosource                      10
#define err_paint_miscall                       11
#define err_inputstring_nosource                12
#define err_misc_oom                            13
#define err_strpaste_nosource                   14
#define err_strextract_nosource                 15


#define errtag_stdisp       1
#define errtag_adisp        2

#define errtag_sfuse        1
#define errtag_stfuse       2



#endif // HYDRESERR_H_INCLUDED
