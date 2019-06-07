#ifndef S_TIMETABLE_H_INCLUDED
#define S_TIMETABLE_H_INCLUDED

#define MAX_FILENAME_LENGTH 31

#include "../include.h"



struct // Structure (type non nomm�) globale, stocke les param�tres dans un format simple et facile � obtenir
{
    UV_list UVlist;
    char UVIDList_Name[MAX_FILENAME_LENGTH];
    int profNum;
    char TchrIDList_Name[MAX_FILENAME_LENGTH];
    int salleNum;
    char RoomIDList_Name[MAX_FILENAME_LENGTH];
    int groupeNum;
    char GrpIDList_Name[MAX_FILENAME_LENGTH];
    char allowedDays;               // tag pour m�moriser les jours


} settings;


#endif // S_TIMETABLE_H_INCLUDED
