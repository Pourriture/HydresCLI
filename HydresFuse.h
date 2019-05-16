#ifndef HYDRESFUSE_H_INCLUDED
#define HYDRESFUSE_H_INCLUDED
#include "HydresCLI.h"

field* fieldFuse(const field* source, const field* aColler, const int pos_x, const int pos_y);
field* fieldFuseST(const field* source, const field* aColler, const int pos_x, const int pos_y);

field* fieldAppendX(const field* left, const field* right);
field* fieldAppendY(const field* up, const field* down);
field* fieldAppend(const field*, const field*, const char);

#endif // HYDRESFUSE_H_INCLUDED
