#include <stdio.h>
#include <stdlib.h>

int main()
{
 int x,y,i=0;
 printf("quelle est le nombre de salle maximal destine au TC?\n");
 scanf("%i",&x);
 printf("quelle est le nombre de matiere dispenser au TC?\n");
 scanf("%i",&y);
 int TELEVE[x];
 int TPROFESSEUR[y];
 int THEURE[y];
 for (i=0;i<x;i++)
 {
   printf("combien y a t il d'eleve dans la %i classe\n",(i+1));
   scanf("%i",&TELEVE[i]);
 }
 for (i=0;i<x;i++)
 {
   printf("combien y a t il de professeur pour la matière %i\n",(i+1));
   scanf("%i",&TPROFESSEUR[i]);
 }
 for (i=0;i<x;i++)
 {
   printf("combien y a t il d'heure de cour dispensé pour la matière %i\n",(i+1));
   scanf("%i",&THEURE[i]);
 }
}
