// bitset.c
// Řešení IJC-DU1, příklad a), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0

#include "bitset.h"

#ifdef USE_INLINE
extern void bitset_free(bitset_t *jmeno_pole);
extern unsigned long bitset_size(bitset_t *jmeno_pole);
extern void bitset_setbit(bitset_t *jmeno_pole, bitset_index_t index, long vyraz);
extern unsigned long bitset_getbit(bitset_t *jmeno_pole, bitset_index_t index);
#endif
