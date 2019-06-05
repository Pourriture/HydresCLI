#ifndef S_TIMETABLE_H_INCLUDED
#define S_TIMETABLE_H_INCLUDED

#define MAX_FILENAME_LENGTH 31

typedef struct timetable timetable;
typedef struct groupe groupe;
typedef struct UV_def UV_def;
typedef struct professeur professeur;
typedef struct edt_part edt_part;
typedef struct salle salle;
typedef struct UV_list UV_list;
typedef enum Ejour Ejour;
typedef enum Tuv Tuv;

struct UV_list
{
    int size;
    UV_def *list;
};

struct // Structure (type non nommée) globale, stocke les paramètres
{
    UV_list UVlist;
    char UVIDList_Name[MAX_FILENAME_LENGTH];
    int profNum;
    char TchrIDList_Name[MAX_FILENAME_LENGTH];
    int salleNum;
    char RoomIDList_Name[MAX_FILENAME_LENGTH];
    int groupeNum;
    char GrpIDList_Name[MAX_FILENAME_LENGTH];


} settings;

struct timetable
{
    long owner;
    edt_part* edt[96*5];
};




enum Ejour
{
    lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche
};

enum Tuv
{
    CM,TD,TP
};

struct groupe
{
    long ID;
    unsigned int effectif;
    UV_def *choixUV[7];
};

struct UV_def
{
    long ID;
    char name[5];
    char hCM, hTD, hTP;     // actually a number, stored in 8 bits for type preserving when writing in files
    int ntCM, ntTD, ntTP;
    professeur *tCM, *tTD, *tTP;
};

struct salle
{
    char name[5];
    long ID;
    short int capacity;
    short int tags;
};
                        // tags d'une salle :
                        // bit 0 : la salle est-elle capable d'accueillir un CM
                        // bit 1 : la salle est-elle capable d'accuielllir un TD
                        // bit 2 : la salle est-elle équipée pour un TP de chimie
                        // bit 3 : la salle peut elle fournir un PC par étudiant (info)
                        // bit 4 : la salle peut-elle fournir un PC pour deux étudiants
struct professeur
{
    long ID;
    short int hoursLeft;
    short int nuCM, nuTD, nuTP;
    UV_def *uCM, *uTD, *uTP;
};

struct edt_part
{
    Ejour jour;
    UV_def *uv;
    Tuv type;
    professeur *teacher;
    char hDebut, hFin, duree;        // les heures sont déterminées par un entier entre 0 et 95
    salle *room;                    // 0 correspond à minuit et 95 à 23h45
};



#endif // S_TIMETABLE_H_INCLUDED
