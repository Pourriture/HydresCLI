#ifndef UV_DAT_H_INCLUDED
#define UV_DAT_H_INCLUDED
#include "s_timetable.h"
#include "stdio.h"
#include "stdlib.h"
#define UV_DATABASE_FILE "UVdat.tt"


typedef struct UV_file UV_file;

struct UV_file
{
    long ID;
    char name[5];
    int hours;      // bits 0 to 7 contain h_CM ;   bits 8 to 15 contain h_TD ; bits 16 to 23 contain h_TP
};

#endif // UV_DAT_H_INCLUDED
