#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 * @argc: number of command line arguments.
 * @arg: array that contains the program command line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *arg[])
{
	int i = 1, n = 500;
	char *str, *token[2];
	char lineptr[100] = {0};
	FILE *stream;
	void (*stack_function)(stack_t **, unsigned int);
	stack_t *lst = NULL;

	if (argc != 2)
		error_stack("USAGE: monty file");
	stream = fopen(arg[1], "r");
	if (stream == NULL)
	{
		str = strcat("Error: Can't open file", arg[1]);
		error_stack(str);
	}
	while (fgets(lineptr, n, stream) != NULL)
	{
		line_arr(lineptr, token);
		if (token[1] != NULL)
			push_value = atoi(token[1]);
		if (token[0] == NULL || token[0][0] == '#')
		{
			i++;
			continue;
		}
		stack_function = get_stack_opt(token[0]);
		if (stack_function == NULL)
		{
			str = str_concat(i, token[0]);
			error_stack(str);
		}
		else
			stack_function(&lst, i);
		i++;
	}
	if (ferror(stream))
	{
		str = strcat("Error: Can't open file <file>", arg[1]);
		error_stack(str);
	}
	exit(EXIT_SUCCESS);
}
