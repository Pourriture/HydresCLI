#ifndef HYDRESADVDISPLAY_H_INCLUDED
#define HYDRESADVDISPLAY_H_INCLUDED
#include "HydresCLI.h"

#include "windows.h"

void fieldCDisplay(const field*, const int s_posx, const int e_posx, const int s_posy, const int e_posy);

void fieldADisplay(const field*);
void fieldACDisplay(const field*, const int s_posx, const int e_posx, const int s_posy, const int e_posy);

#endif // HYDRESADVDISPLAY_H_INCLUDED
