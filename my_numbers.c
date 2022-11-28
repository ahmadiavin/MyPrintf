#include <unistd.h>
#include "my_printf.h"
// d
void my_int(int number, int *length)
{
    if (number < 0)
    {
        my_putchar_len('-', length);
        my_int(number * -1, length);
    }
    else
    {
        if (number > 9) my_int(number / 10, length);
        my_putchar_len(number % 10 + '0', length);
    }
}
// u
void my_unsigned_int(unsigned int u, int *length)
{
    if (u >= 10) my_unsigned_int(u / 10, length);
    my_putchar_len(u % 10 + '0', length);
}
// x
void my_hex(unsigned int x, int *length, char hex)
{
    char str[25];
    char *baseChar;
    int i;
    if (hex == 'X')
        baseChar = "0123456789ABCDEF";
    else
        baseChar = "0123456789abcdef";
    i = 0;
    if (x == 0)
    {
        my_putchar_len('0', length);
        return;
    }
    while (x != 0)
    {
        str[i] = baseChar[x % 16];
        x = x / 16;
        i++;
    }
    while (i--) my_putchar_len(str[i], length);
}
void my_octal(unsigned int o, int *length, char octal)
{
    char str[25];
    char *baseChar;
    int i;
    if (octal == 'O')
        baseChar = "0123456789ABCDEF";
    else
        baseChar = "0123456789abcdef";
    i = 0;
    if (o == 0)
    {
        my_putchar_len('0', length);
        return;
    }
    while (o != 0)
    {
        str[i] = baseChar[o % 8];
        o = o / 8;
        i++;
    }
    while (i--) my_putchar_len(str[i], length);
}
// p
void my_pointer(size_t pointer, int *length)
{
    char str[25];
    char *baseChar;
    int i;
    baseChar = "0123456789abcdef";
    i = 0;
    write(1, "0x", 2);
    (*length) += 2;
    if (pointer == 0)
    {
        my_putchar_len('0', length);
        return;
    }
    while (pointer != 0)
    {
        str[i] = baseChar[pointer % 16];
        pointer = pointer / 16;
        i++;
    }
    while (i--)
    {
        my_putchar_len(str[i], length);
    }
}