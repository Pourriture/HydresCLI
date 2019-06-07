#ifndef S_SALLE_H_INCLUDED
#define S_SALLE_H_INCLUDED
typedef struct salle salle;

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
                        // bit 2 : la salle est-elle �quip�e pour un TP de chimie
                        // bit 3 : la salle peut elle fournir un PC par �tudiant (info)
                        // bit 4 : la salle peut-elle fournir un PC pour deux �tudiants





#endif // S_SALLE_H_INCLUDED
