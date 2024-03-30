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
	char *result;
	char p = '0' + i;
	char str[100];

	str[0] = '\0';
	strcat(str, "L");
	strncat(str, &p, 1);
	strcat(str, ": unknown instruction ");
	strcat(str, fori);
	result = malloc(strlen(str) + 1);
	if (result == NULL)
		return NULL;
	strcpy(result, str);
	return (result);
}

/**
 * line_arr - Prints our error to the standard output.
 * Description: Function that push a int to a stack.
 * @p: a char[], error message.
 *
 * Return: array.
 */
void line_arr(char *str, char **strarr)
{
	int i = 0;

        strarr[0] = NULL;
	str = strtok(str, " \n$");
	while(str != NULL)
	{
		strarr[i] = malloc(strlen(str) + 1);
		if (strarr[i] == NULL)
			error_stack("Error: malloc failed\n");
		strcpy(strarr[i], str);
		i++;
		if (i == 2)
			return;
		str = strtok(NULL, " \n$");
	}
	strarr[1] = NULL;
}
