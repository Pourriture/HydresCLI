#include <stdio.h>
#include <stdlib.h>

int main()
{
     int x,y;
     int *pointeurx,*pointeury;
     pointeurx=&x;
     pointeury=&y;
     FILE *fichier = NULL;
     fichier = fopen("RecupCondIni.txt","r+");
     if (fichier != NULL)
     {
         printf("quelle est le nombre de salle maximal destine au TC?\n");
         scanf("%i",&x);
         printf("quelle est le nombre de matiere dispenser au TC?\n");
         scanf("%i",&y);
         int TELEVE[x];
         int TPROFESSEUR[y];
         int THEURE[y];
         conditioninitial(TELEVE,TPROFESSEUR,THEURE,pointeurx,pointeury);
         fprintf(fichier,"le nombre de salle maximal est %i\n",x);
         fprintf(fichier,"le nombre de matiere a dispenser en tc est de %i\n",y);
         for(i=0)
         fclose(fichier);
     }
     else
     {
        printf("Impossible d'ouvrir le fichier RecupCondIni");
     }

}
