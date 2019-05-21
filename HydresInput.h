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


// Hydres utilise pour le moment ConIO pour prendre en compte les entrées de l'utilisateur

/** appelle getch() et renvoie UPKEY, DOWNKEY, LEFTKEY, RIGHTKEY suivant l'entrée de l'utilisateur */
int ArrowGet();

/** renvoie ce qui a été renvoyé par l'utilisateur */
int KeyGet();

/** renvoie le premier caractère qui sera pressé par l'utilisateur */
int CharGet();

/** renvoie une chaîne de caractères entrée par l'utilisateur, affichée pendant l'input sur l'écran de manière dynamique. un peu de latence. préférez scanf ou fgets. si vous n'êtes pas intéressé par la sortie, veuillez utiliser fieldInStr */
char* fieldInputString(field*, int posx, int posy, int length);

/** fieldInputString, mais sans sortie */
void fieldInStr(field*, int posx, int posy, int length);

#endif // HYDRESINPUT_H_INCLUDED
