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


// Hydres utilise pour le moment Conio pour prendre en compte les entrées de l'utilisateur

int ArrowGet();

int KeyGet();

int CharGet();

char* fieldInputString(field*, int posx, int posy, int length);


#endif // HYDRESINPUT_H_INCLUDED
