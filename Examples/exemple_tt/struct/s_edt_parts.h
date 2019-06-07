#ifndef S_EDT_PARTS_INCLUDED
#define S_EDT_PARTS_INCLUDED
#include "s_UV.h"
#include "s_salle.h"

typedef struct timetable timetable;
typedef struct edt_part edt_part;
typedef enum jour_def jour_def;

enum jour_def
{
    lundi = 0,
    mardi = 1,
    mercredi = 2,
    jeudi = 3,
    vendredi = 4,
    samedi = 5,
    dimanche = 6
};

struct edt_part
{
    jour_def jour;
    UV_def *uv;
    Tuv type;
    professeur *teacher;
    char hDebut, hFin, duree;       // les heures sont déterminées par un entier entre 0 et 95
    salle *room;                    // 0 correspond à minuit et 95 à 23h45
};

struct timetable
{
    long owner;
    edt_part* edt[96*7];
};


#endif // S_EDT_PARTS_INCLUDED
