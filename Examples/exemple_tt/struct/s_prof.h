#ifndef S_PROF_H_INCLUDED
#define S_PROF_H_INCLUDED

#include "s_typedef_uvp.h"
#include "s_UV.h"






struct professeur
{
    long ID;                // sauver
    char name[30];          // sauver
    short int hoursLeft;    // sauver (heures max d'un prof)
    short int nuCM, nuTD, nuTP;
    UV_def *uCM, *uTD, *uTP;
};


#endif // S_PROF_H_INCLUDED
