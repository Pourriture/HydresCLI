#include <stdio.h>
#include <stdlib.h>

int main()
{
     int x,y,i,e;
     int *pointeurx,*pointeury;
     pointeurx=&x;
     pointeury=&y;
     FILE *fichier = NULL;
     fichier = fopen("RecupCondIni.txt","r+");
     if (fichier != NULL)
     {


         printf("quelle est le nombre de salle maximal destine au TC01?\n");
         scanf("%i",&x);
         printf("quelle est le nombre de matiere dispensee au TC01?\n");
         scanf("%i",&y);
         printf("quelle est le nombre d eleve a accueillir en TC01 ");
         scanf("%i",&e);
         int TELEVE[x];
         int TPROFESSEUR[y];
         int THEURE[y];
         conditioninitial(TELEVE,TPROFESSEUR,THEURE,pointeurx,pointeury);
         fprintf(fichier,"le nombre de salle maximal destine au TC01 est %i\n",x);
         fprintf(fichier,"le nombre de matiere a dispenser en TC01 est de %i\n",y);
         fprintf(fichier,"le nombre d'eleve a accueillir en TC01 est de %i\n",e);


         for(i=0;i<x;i++)

         {

             fprintf(fichier,"le nombre d'eleve dans la salle %i est %i\n",(i+1),TELEVE[i]);

         }

         for(i=0;i<y;i++)
         {

             fprintf(fichier,"le nombre de professeur pour la matiere %i est %i\n",(i+1),TPROFESSEUR[i]);
             fprintf(fichier,"le nombre d'heure a dispenser pour la matiere %i est %i\n",(i+1),THEURE[i]);

         }

         fclose(fichier);
     }

     else

     {

        printf("Impossible d'ouvrir le fichier RecupCondIni");

     }

}
