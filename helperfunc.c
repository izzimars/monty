#include "main.h"

/**
 * error_stack - Prints our error to the standard output.
 * Description: Function that push a int to a stack.
 * @s: a char[], error message.
 *
 * Return: None
 */
void error_stack(char *s)
{
	write(2, s, strlen(s));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * str_concat - Prints our error to the standard output.
 * Description: Function that push a int to a stack.
 * @i: a char[], error message.
 * @fori: a string.
 *
 * Return: string.
 */
char *str_concat(int i, char *fori)
{
	char p;
	char *str;

	p = '0' + i;
	str = strcat("L", &p);
	str = strcat(str, ": unknown instruction ");
	str = strcat(str, fori);
	return (str);
}

