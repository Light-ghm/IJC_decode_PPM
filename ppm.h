// ppm.h
// Řešení IJC-DU1, příklad b), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0
#include <stdlib.h>
#include "error.h"
#include <string.h>
#ifndef JAZYKC_PPM_H
#define JAZYKC_PPM_H

#define PPMLIMIT 8000*8000*3

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

#endif //JAZYKC_PPM_H
