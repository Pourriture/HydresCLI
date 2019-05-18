#ifndef HYDRESADVDISPLAY_H_INCLUDED
#define HYDRESADVDISPLAY_H_INCLUDED
#include "HydresCLI.h"
#include "windows.h"

/** Affiche une partie d'un écran entre s_posx et e_posy */
void fieldCDisplay(const field*, const int s_posx, const int e_posx, const int s_posy, const int e_posy);

/** Affiche un écran entier avec sa couleur */
void fieldADisplay(const field*);

/** Affiche une partie d'un écran entre s_posx, e_posx, s_posy et e_posy avec sa couleur */
void fieldACDisplay(const field*, const int s_posx, const int e_posx, const int s_posy, const int e_posy);

#endif // HYDRESADVDISPLAY_H_INCLUDED
