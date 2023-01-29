// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0
// Používam bitset_alloc(jmeno_pole,VELIKOST); lebo mám problém s príkazom ulimit -s, na svojom PC môžem len zmenšiť stack,
//ak sa snažím zväčšiť hlási chybu, na merlinovi je dosť miesta defaultne a odtestoval som tam bitset_create a aj tam funguje ulimit -s,
//ale nefunguje z Makefilu...
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"
#define VELIKOST 300000000

int main(){

    clock_t start = clock();

    unsigned long prvocisla[10] = {0};
    unsigned long pocet = 10;

    bitset_alloc(jmeno_pole,VELIKOST);
    //bitset_create(jmeno_pole,VELIKOST);
    Eratosthenes(jmeno_pole);


    for(unsigned long i = VELIKOST-1; i>0 && pocet > 0; --i)
        if((bitset_getbit(jmeno_pole, i)) == 0) prvocisla[--pocet] = i;


    for(unsigned long i = 0; i < 10; ++i)
        printf("%lu\n", prvocisla[i]);


    bitset_free(jmeno_pole);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
}