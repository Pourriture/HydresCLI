#ifndef HYDRESFUSE_H_INCLUDED
#define HYDRESFUSE_H_INCLUDED
#include "HydresCLI.h"

/** renvoit une fusion deux �crans � partir de la position pos_x, pos_y */
field* fieldFuse(const field* source, const field* aColler, const int pos_x, const int pos_y);

/** renvoit une fusion de deux �crans � partir de la position pos_x, pos_y, les caract�res ' ' de aColler ne sont pas copi�s */
field* fieldFuseST(const field* source, const field* aColler, const int pos_x, const int pos_y);

/** colle deux �crans � l'horizontale et renvoie le r�sultat */
field* fieldAppendX(const field* left, const field* right);

/** colle deux �crans � la verticale et renvoie le r�sultat */
field* fieldAppendY(const field* up, const field* down);

/** colle deux �crans � l'horizontale ou � la verticale selon que le troisi�me param�tre soit X ou Y */
field* fieldAppend(const field*, const field*, const char);

#endif // HYDRESFUSE_H_INCLUDED
