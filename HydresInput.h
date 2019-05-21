#ifndef HYDRESINPUT_H_INCLUDED
#define HYDRESINPUT_H_INCLUDED
#include "HydresCLI.h"
#include "HydresString.h"
#include "HydresAdvDisplay.h"
#include "HydresColor.h"
#include "conio.h"

#define MAX_INPUT_LENGTH 100

#define LEFTKEY -300
#define UPKEY -301
#define RIGHTKEY -302
#define DOWNKEY -303
#define ENTERKEY 13
#define ERASEKEY 8
#define TABKEY 9


// Hydres utilise pour le moment ConIO pour prendre en compte les entr�es de l'utilisateur

/** appelle getch() et renvoie UPKEY, DOWNKEY, LEFTKEY, RIGHTKEY suivant l'entr�e de l'utilisateur */
int ArrowGet();

/** renvoie ce qui a �t� renvoy� par l'utilisateur */
int KeyGet();

/** renvoie le premier caract�re qui sera press� par l'utilisateur */
int CharGet();

/** renvoie une cha�ne de caract�res entr�e par l'utilisateur, affich�e pendant l'input sur l'�cran de mani�re dynamique. un peu de latence. pr�f�rez scanf ou fgets. si vous n'�tes pas int�ress� par la sortie, veuillez utiliser fieldInStr */
char* fieldInputString(field*, int posx, int posy, int length);

/** fieldInputString, mais sans sortie */
void fieldInStr(field*, int posx, int posy, int length);

#endif // HYDRESINPUT_H_INCLUDED
