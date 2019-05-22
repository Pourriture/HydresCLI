#include <stdio.h>
#include <stdlib.h>

int main()
{
 int x,y;
 int *pointeurx,*pointeury;
 pointeurx=&x;
 pointeury=&y;
 printf("quelle est le nombre de salle maximal destine au TC?\n");
 scanf("%i",&x);
 printf("quelle est le nombre de matiere dispenser au TC?\n");
 scanf("%i",&y);
 int TELEVE[x];
 int TPROFESSEUR[y];
 int THEURE[y];
 conditioninitial(TELEVE,TPROFESSEUR,THEURE,pointeurx,pointeury);
}
