#include "my_printf.h"
#include <stdio.h>

static void my_conversion_check(char s, va_list *args, int *len, int *i)
{
    if (s == 's')
        my_string(va_arg(*args, char *), len);
    else if (s == 'd' || s == 'i')
        my_int(va_arg(*args, int), len);
    else if (s == 'o')
        my_octal(va_arg(*args, unsigned int), len, 'o');
    else if (s == 'u')
        my_unsigned_int(va_arg(*args, unsigned int), len);
    else if (s == 'x')
        my_hex(va_arg(*args, unsigned int), len, 'x');
    else if (s == 'X')
        my_hex(va_arg(*args, unsigned int), len, 'X');
    else if (s == 'p')
        my_pointer(va_arg(*args, size_t), len);
    else if (s == 'c')
        my_putchar_len(va_arg(*args, int), len);
    else if (s == '%')
        my_putchar_len('%', len);
    else
        (*i)--;
}

int my_printf(const char *string, ...)
{
    va_list args;
    int i, len;
    i = 0;
    len = 0;
    va_start(args, string);
    while (string[i] != '\0')
    {
        if (string[i] == '%')
        {
            i++;
            my_conversion_check(string[i], &args, &len, &i);
            i++;
        }
        else
        {
            my_putchar_len((char)string[i], &len);
            i++;
        }
    }
    va_end(args);
    return (len);
}

int main()
{
    // int result = my_printf("Testing\n");
    // int result2 = printf("Testing\n");
    // char result3 = my_printf("C\n");

    // my_printf("%d-%d-%d!", 2048, 0, -1337);
    my_printf("%o!\n", 100);
    // my_printf("hey guys");
    my_printf("%X!\n", 14);

    // printf("\nresult = %d\nresult2 = %d\n result3 = %d", result, result2,
    //        result3);
}