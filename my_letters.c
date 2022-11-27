#include "my_printf.h"
void my_putchar_len(char character, int *length)
{
    write(1, &character, 1);
    (*length)++;
}

void my_string(char *args, int *length)
{
    size_t i;
    i = 0;
    if (!args)
    {
        write(1, "(null)", 6);
        (*length) += 6;
        return;
    }
    while (args[i] != '\0')
    {
        my_putchar_len(args[i], length);
        i++;
    }
}