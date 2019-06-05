#ifndef HYDRESCOLOR_H_INCLUDED
#define HYDRESCOLOR_H_INCLUDED
#include "HydresCLI.h"
#include "windows.h"

#define BACKGROUND_WHITE BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED
#define FOREGROUND_WHITE FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED


/**
Color Guide for use with SetConsoleTextAttribute

FOREGROUND_BLUE 	        Text color contains blue.
FOREGROUND_GREEN 	        Text color contains green.
FOREGROUND_RED 	            Text color contains red.
FOREGROUND_INTENSITY 	    Text color is intensified.
BACKGROUND_BLUE 	        Background color contains blue.
BACKGROUND_GREEN 	        Background color contains green.
BACKGROUND_RED 	            Background color contains red.
BACKGROUND_INTENSITY 	    Background color is intensified.
COMMON_LVB_LEADING_BYTE 	Leading byte.
COMMON_LVB_TRAILING_BYTE 	Trailing byte.
COMMON_LVB_GRID_HORIZONTAL 	Top horizontal.
COMMON_LVB_GRID_LVERTICAL 	Left vertical.
COMMON_LVB_GRID_RVERTICAL 	Right vertical.
COMMON_LVB_REVERSE_VIDEO 	Reverse foreground and background attributes.
COMMON_LVB_UNDERSCORE 	    Underscore.

*/

/** Change la couleur d'un écran entier. */
void fieldPaint(field*, const int color);

/** Change la couleur d'une partie d'un écran. */
void fieldPaintPart(field*, const int color, const int s_x, const int e_x, const int s_y, const int e_y);

/** Renvoie une copie de l'écran argument, colorée.*/
field* fieldCPaint(const field*, const int color);

/** Renvoie une copie de l'écran argument dont une partie a été colorée. */
field* fieldCPaintPart(const field*, const int color, const int s_x, const int e_x, const int s_y, const int e_y);


#endif // HYDRESCOLOR_H_INCLUDED
