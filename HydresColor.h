#ifndef HYDRESCOLOR_H_INCLUDED
#define HYDRESCOLOR_H_INCLUDED
#include "HydresCLI.h"

void fieldPaint(field*, const int color);
void fieldPaintPart(field*, const int color, const int s_x, const int e_x, const int s_y, const int e_y);
field* fieldCPaint(const field*, const int color);
field* fieldCPaintPart(const field*, const int color, const int s_x, const int e_x, const int s_y, const int e_y);


#endif // HYDRESCOLOR_H_INCLUDED
