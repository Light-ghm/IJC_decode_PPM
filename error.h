// error.h
// Řešení IJC-DU1, příklad b), 20.3.2022
// Autor: Marián Backa, FIT
// Přeloženo: gcc 9.3.0
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef JAZYKC_ERROR_H
#define JAZYKC_ERROR_H
void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);
#endif //JAZYKC_ERROR_H
