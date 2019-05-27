
#include <stdio.h>
#include <stdlib.h>

void conditioninitial(int TELEVE[],int TPROFESSEUR[],int THEURE[],int *pointeurx,int *pointeury)
{
 int i=0;
 for (i=0;i<*pointeurx;i++)
 {
   printf("combien y a t il d'eleve dans la %i salle\n",(i+1));
   scanf("%i",&TELEVE[i]);
 }
 for (i=0;i<*pointeury;i++)
 {
   printf("combien y a t il de professeur pour la matiere %i\n",(i+1));
   scanf("%i",&TPROFESSEUR[i]);
 }
 for (i=0;i<*pointeury;i++)
 {
   printf("combien y a t il d heure de cour dispense pour la matiere %i\n",(i+1));
   scanf("%i",&THEURE[i]);
 }
}
