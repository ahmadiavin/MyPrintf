#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_printf(const char *string,...);
void my_string(char *args, int *length); // S -string
void my_putchar_len(char character, int *length); // C - character
void my_int(int number, int *length); // D - signed decimal
void my_unsigned_int(unsigned int u, int *length); // U - unsigned int
void my_hex(unsigned int x, int *length, char hex); // X - unsigned hex
void my_octal(unsigned int o, int *length, char octal); // O - unsigned octal
void my_pointer(size_t pointer, int *length); // P - pointer

#endif