// error.c
// Řešení IJC-DU1, příklad b), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0
#include "error.h"

void warning_msg(const char *fmt, ...){
    va_list argslist;
    va_start(argslist, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, argslist);
    va_end(argslist);
}

void error_exit(const char *fmt, ...){
    va_list argslist;
    va_start(argslist, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, argslist);
    va_end(argslist);
    exit(1);
}