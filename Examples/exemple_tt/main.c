#include <stdio.h>
#include <stdlib.h>
#include "include.h"


int main()
{
    int tableau[5];
    printf("adresse tableau %p\n",tableau);



    printf("edt_part %d bytes\n",sizeof(edt_part));
    printf("professeur %d bytes\n",sizeof(professeur));
    printf("UV_def %d bytes\n",sizeof(UV_def));
    printf("groupe %d bytes\n",sizeof(groupe));
    printf("salle %d bytes\n",sizeof(salle));
    printf("Tuv %d bytes\n",sizeof(Tuv));
    printf("Ejour %d bytes\n",sizeof(jour_def));

    printf("\n\n int %d bytes\n short int %d bytes \n char %d bytes\n",sizeof(int),sizeof(short int),sizeof(char));

    printf("\n0x1 %d\n0x100 %d\n0x10000 %d\n",0x1, 0x100, 0x10000);



    fputs("\naadfafz\nfdazzf\nfafagae\ngezgezg",stdout);

    return 0;
}


void timetable_Do();
void getDataList(void);
void UV_Init(UV_def *UV, int n);
void salle_Init(salle *room, int n);
void groupe_Init(groupe *grp, int n, const UV_list *list);
void prof_Init(professeur *prof, int n, const UV_list *list);
UV_def* findUV(const UV_list *list, long ID);


void timetable_Do()
{

    getDataList(/* settings */);


    int i;

    // premi�rement : on initialise les UVs
    settings.UVlist.list = malloc(settings.UVlist.size * sizeof(*settings.UVlist.list));
    for (i = 0 ; i < settings.UVlist.size ; i++)
        UV_Init(&settings.UVlist.list[i] , i);
        // Envoyer UVlist[i] ferait faire copier au programme ce qui est situ� � l'adresse point�e par UVlist + i * sizeof(*UVlist), ce qui signifie que l'UV que l'on cherche � modifier ne le sera pas. Pour �viter ce probl�me, on envoie comme argument l'adresse de l'�l�ment UVlist[i].


    // deuxi�mement : on initialise les salles
    salle *salleList = malloc(settings.salleNum * sizeof(*salleList));
    for (i = 0 ; i < settings.salleNum ; i++)
        salle_Init(&salleList[i], i);

    // troisi�mement : on initialise les groupes
    groupe *groupeList = malloc(sizeof(*groupeList) * settings.groupeNum);
    for (i = 0 ; i < settings.groupeNum ; i++)
        groupe_Init(&groupeList[i], i, &settings.UVlist);

    // quatri�mement : on initialise les professeurs
    professeur *profList = malloc(sizeof(*profList) * settings.profNum);
    for (i = 0 ; i < settings.profNum ; i++)
        prof_Init(&profList[i], i, &settings.UVlist);



    /*
        work


    */


    // gotta delete stuff then!
    free(profList);
    free(groupeList);
    free(salleList);
    free(settings.UVlist.list);

}

void getDataList(/* settings */)
{
    // Initialise les valeurs de settings ?
}

void UV_Init(UV_def *UV, int n)
{
    // Initialise une salle selon un fichier entr�e contenant des IDs (on reconna�tra le bon ID gr�ce au param�tre n) et sa correspondance dans la base de donn�es
    // Une fois ceci fait, sachant que les professeurs sont initialis�s apr�s les UVs :


    UV->ntCM = 0;
    UV->ntTD = 0;
    UV->ntTP = 0;
    UV->tCM = NULL;
    UV->tTD = NULL;
    UV->tTP = NULL;

}

void salle_Init(salle *room, int n)
{
    // Initialise une salle selon un fichier entr�e contenant des IDs (on reconna�tra le bon ID gr�ce au param�tre n) et sa correspondance dans la base de donn�es

}

void groupe_Init(groupe *grp, int n, const UV_list *list)
{
    // Initialise un groupe selon un fichier entr�e contenant des IDs (on reconna�tra le bon ID gr�ce au param�tre n) et sa correspondance dans la base de donn�es
    // On utilisera une fonction findUV(const *UV_list list, long ID) pour r�cup�rer les pointeurs vers les bons �l�ments de la liste et les stocker dans grp->choixUV

}

void prof_Init(professeur *prof, int n, const UV_list *list)
{
    // Initialise un professeur selon un fichier entr�e contenant des IDs (on reconna�tra le bon ID gr�ce au param�tre n) et sa correspondance dans la base de donn�es
    // On utilisera une fonction findUV(const *UV_list list, long ID) pour r�cup�rer les pointeurs vers les bons �l�ments de la liste et les stocker dans prof->uCM, prof->uTD, prof->uTP

}

UV_def* findUV(const UV_list *list, long ID)
{
    int i;
    for (i = 0 ; i < list->size ; i++)
    {
        if (list->list[i].ID == ID)
            return &(list->list[i]);
    }
    return NULL;
}
