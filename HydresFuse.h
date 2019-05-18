#ifndef HYDRESFUSE_H_INCLUDED
#define HYDRESFUSE_H_INCLUDED
#include "HydresCLI.h"

/** renvoit une fusion deux écrans à partir de la position pos_x, pos_y */
field* fieldFuse(const field* source, const field* aColler, const int pos_x, const int pos_y);

/** renvoit une fusion de deux écrans à partir de la position pos_x, pos_y, les caractères ' ' de aColler ne sont pas copiés */
field* fieldFuseST(const field* source, const field* aColler, const int pos_x, const int pos_y);

/** colle deux écrans à l'horizontale et renvoie le résultat */
field* fieldAppendX(const field* left, const field* right);

/** colle deux écrans à la verticale et renvoie le résultat */
field* fieldAppendY(const field* up, const field* down);

/** colle deux écrans à l'horizontale ou à la verticale selon que le troisième paramètre soit X ou Y */
field* fieldAppend(const field*, const field*, const char);

#endif // HYDRESFUSE_H_INCLUDED
