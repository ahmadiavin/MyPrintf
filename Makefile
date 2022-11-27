my_printf: my_printf.c
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address my_printf.c my_printf.h my_letters.c my_numbers.c -o my_printf

clean:
	rm -f *.o

fclean: clean
	rm -f my_printf