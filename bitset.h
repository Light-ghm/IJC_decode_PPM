// bitset.h
// Řešení IJC-DU1, příklad a), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0
#ifndef BITSET
#define BITSET

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include "error.h"

typedef unsigned long bitset_t;

typedef unsigned long bitset_index_t;

#define REAL_SIZE(velikost) (((velikost)%(CHAR_BIT*sizeof(unsigned long)) == 0 ? (velikost)/(CHAR_BIT*sizeof(unsigned long)) : (velikost)/(CHAR_BIT*sizeof(unsigned long))+1)+1)  //+1 lebo prvy prvok nastavujeme na velkost tohto pola tak extra miesto pren

#define bitset_create(jmeno_pole,velikost)  static_assert(((velikost)>0), "Pole bitov alokujte s veľkosťou > 0");\
                                    bitset_t (jmeno_pole)[REAL_SIZE(velikost)];\
                                    for(unsigned long i = 1; i < REAL_SIZE(velikost); i++) jmeno_pole[i] = 0;\
                                    (jmeno_pole)[0]=(unsigned long)velikost

#define bitset_alloc(jmeno_pole,velikost) assert((velikost)>0 && (velikost) <= ULONG_MAX);\
                                    bitset_t* (jmeno_pole) = calloc(REAL_SIZE(velikost), sizeof(unsigned long)); \
                                    if((jmeno_pole) == NULL)  error_exit("bitset_alloc: Chyba alokace paměti");\
                                    jmeno_pole[0]=(velikost)

#ifndef USE_INLINE

#define bitset_free(jmeno_pole) free((jmeno_pole))
#define bitset_size(jmeno_pole) (jmeno_pole)[0]

#define bitset_setbit(jmeno_pole, index, vyraz) \
                                    (((unsigned long)(index) >= (unsigned long)(jmeno_pole[0])) ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)((bitset_size(jmeno_pole))-1)), 9 : \
                                    (vyraz) ? (jmeno_pole)[((unsigned long)(index) / (sizeof(unsigned long)*CHAR_BIT)) + 1] |= (unsigned long)((unsigned long)0x1 << (unsigned long)((unsigned long)index % ((sizeof(unsigned long)*CHAR_BIT)))) : \
                                    (jmeno_pole[((unsigned long)(index) / (sizeof(unsigned long)*CHAR_BIT)) + 1] &= ((unsigned long)~((unsigned long)0x1 << (unsigned long)((unsigned long)index % (sizeof(unsigned long)*CHAR_BIT))))))

#define bitset_getbit(jmeno_pole,index) \
                                    (((unsigned long)index >= (unsigned long)jmeno_pole[0]) ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)((bitset_size(jmeno_pole))-1)), 9 : \
                                    ((jmeno_pole)[((unsigned long)(index) / (sizeof(unsigned long)*CHAR_BIT)) + 1] & ((unsigned long)0x1 << ((unsigned long)index % ((sizeof(unsigned long)*CHAR_BIT))) )) ? 1 : 0)

#else
//using inline functions

inline void bitset_free(bitset_t* jmeno_pole){
    free(jmeno_pole);
}

inline unsigned long bitset_size(bitset_t* jmeno_pole){
    return jmeno_pole[0];
}

inline void bitset_setbit(bitset_t* jmeno_pole, bitset_index_t index, long vyraz){
    if(index > jmeno_pole[0]){
       error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)(bitset_size(jmeno_pole)-1));
    }else{
        if(vyraz){
            jmeno_pole[((unsigned long)index / (sizeof(unsigned long)*CHAR_BIT)) + 1] |= (unsigned long)((unsigned long)0x1 << ((unsigned long)index % (sizeof(unsigned long)*CHAR_BIT)));
        }else{
            jmeno_pole[((unsigned long)index / (sizeof(unsigned long)*CHAR_BIT)) + 1] &= (unsigned long)~((unsigned long)0x1 << ((unsigned long)index % (sizeof(unsigned long)*CHAR_BIT)));
        }
    }
}

inline unsigned long bitset_getbit(bitset_t* jmeno_pole,bitset_index_t index){
    if(index > jmeno_pole[0]){
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)(bitset_size(jmeno_pole)-1));
        return 1;
    }else{
        return (jmeno_pole[((index) / (sizeof(unsigned long)*CHAR_BIT)) + 1] & ((unsigned long)0x1 << (index % (sizeof(unsigned long)*CHAR_BIT))));
    }
}

#endif //USE_INLINE

#endif //BITSET