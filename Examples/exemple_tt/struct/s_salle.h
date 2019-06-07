#ifndef S_SALLE_H_INCLUDED
#define S_SALLE_H_INCLUDED
typedef struct salle salle;

struct salle
{
    long ID;                // sauver
    char name[5];           // sauver
    short int capacity;     // sauver
    short int tags;         // sauver
};
                        // tags d'une salle :
                        // bit 0 : la salle est-elle capable d'accueillir un CM
                        // bit 1 : la salle est-elle capable d'accuielllir un TD
                        // bit 2 : la salle est-elle équipée pour un TP de chimie
                        // bit 3 : la salle peut elle fournir un PC par étudiant (info)
                        // bit 4 : la salle peut-elle fournir un PC pour deux étudiants





#endif // S_SALLE_H_INCLUDED
