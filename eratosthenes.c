// eratosthenes.c
// Řešení IJC-DU1, příklad a), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0
#include "eratosthenes.h"
#include <math.h>
void Eratosthenes(bitset_t* pole){

    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);

    for (unsigned long i = 2; i < sqrt(bitset_size(pole)-1); i++)
    {
        // získavanie prvočísel od najmenšieho a vyradzovanie všetkých čísel čo sú ich násobky
        if ((bitset_getbit(pole, i)) == 0) {
            for (unsigned long j = 2; i*j < bitset_size(pole); j++)
                bitset_setbit(pole, i*j, 1);
        }
    }
}
