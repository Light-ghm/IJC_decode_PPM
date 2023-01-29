// ppm.c
// Řešení IJC-DU1, příklad b), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0
#include "ppm.h"

void ppm_free(struct ppm *p){
    free(p);
}

struct ppm * ppm_read(const char * filename){

    unsigned x,y,colorrange;
    FILE * ppmko;
    if((ppmko = fopen(filename, "rb")) == NULL){
        warning_msg("Nepodarilo sa otvoriť obrázok %s!\n",filename);
        return NULL;
    }
    char p6[3] = {'\0'};
    fscanf(ppmko,"%s %u %u %u",p6,&x, &y, &colorrange);
    if(strcmp(p6,"P6")){
        warning_msg("Nesprávny formát hlavičky %s suboru %s!\n",p6,filename);
        fclose(ppmko);
        return NULL;
    }
    if(colorrange != 255){
        warning_msg("Nesprávny  formát hlavičky, max. intenzita farby nie je 255 ale je %d!\n",colorrange);
        fclose(ppmko);
        return NULL;
    }
    if(x*y*3>PPMLIMIT){
        warning_msg("Prílyž veľký obrázok: %d, max. podporovaná veľkosť: 8000*8000*3!\n",x*y*3);
        fclose(ppmko);
        return NULL;
    }

    struct ppm *obrazok = malloc(x*y*3 + sizeof(struct ppm));

    if(obrazok == NULL){
        fclose(ppmko);
        error_exit("Nepodarilo sa alokovať pamäť pre načítanie obrázka\n");
    }

    obrazok->xsize = x;
    obrazok->ysize = y;
    fgetc(ppmko); // odstránenie whitespace znaku

    //načítať binárne dáta obrázku
    fread(obrazok->data, x*y*3, 1, ppmko);


    fclose(ppmko);
    return obrazok;

}