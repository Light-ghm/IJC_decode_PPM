// steg-decode.c
// Řešení IJC-DU1, příklad b), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"

int main(int argc, char *argv[]){

    if(argc != 2) error_exit("Nesprávny počet argumentov!\n");

    struct ppm* obrazok;

    if((obrazok = ppm_read(argv[1])) == NULL) {
        error_exit("Nepodarilo sa načítať obrázok!\n");
    }


    bitset_alloc(dataObrazku, obrazok->xsize*obrazok->ysize*3);
    Eratosthenes(dataObrazku);

    char znakCast = 0;
    char znak = 0;
    unsigned int position = 0;
    int spravaKoniec = 0;


    for(unsigned long i = 29; i < obrazok->xsize*obrazok->ysize*3; ++i){

        if((bitset_getbit(dataObrazku, i))) continue; //if not prime number -> skip

        znakCast = (obrazok->data[i]%2 == 0) ? 0 : 1;
        znak |= znakCast << position;
        position++;
        if(position == 8){     //naplnili sme char
            if(znak == '\0'){
                putchar(znak);
                putchar('\n'); //odriadkujeme
                spravaKoniec = 1;
                break;
            }

            putchar(znak);
            znak = 0;
            position = 0;
        }

    }

    if(spravaKoniec ==0) {
        ppm_free(obrazok);
        bitset_free(dataObrazku);
        error_exit("Správa nie je správne ukončená!\n");
    }



    ppm_free(obrazok);
    bitset_free(dataObrazku);

}