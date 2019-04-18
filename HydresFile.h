#ifndef HYDRESFILE_H_INCLUDED
#define HYDRESFILE_H_INCLUDED
#include "HydresCLI.h"
#include <string.h>
#include <errno.h>


field* fieldFromFile(const char*);
void fieldToFile(const char*, const field*);


#endif // HYDRESFILE_H_INCLUDED
