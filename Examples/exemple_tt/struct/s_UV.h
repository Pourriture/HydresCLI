#ifndef S_UV_H_INCLUDED
#define S_UV_H_INCLUDED

#include "s_typedef_uvp.h"
#include "s_prof.h"



typedef struct UV_list UV_list;
typedef enum Tuv Tuv;

struct UV_list
{
    int size;
    UV_def *list;
};

enum Tuv
{
    CM,TD,TP
};

struct UV_def
{
    long ID;
    char name[5];
    char hCM, hTD, hTP;     // actually a number, stored in 8 bits for type preserving when writing in files
    int ntCM, ntTD, ntTP;
    professeur *tCM, *tTD, *tTP;
};


#endif // S_UV_H_INCLUDED
