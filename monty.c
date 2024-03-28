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
	char *str, (*token), (*opcode);
	char lineptr[100] = {0};
	FILE *stream;
	void (*stack_function)(stack_t **, unsigned int);
	stack_t *lst = NULL;

	token = NULL;
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
		str = strtok(lineptr, " $");
		opcode = str;
		token = strtok(NULL, " $");
		if (token != NULL)
			push_value = atoi(token);
		stack_function = get_stack_opt(str);
		if (stack_function == NULL)
		{
			str = str_concat(i, opcode);
			error_stack(str);
		}
		else
			stack_function(&lst, push_value);
		i++;
	}
	if (ferror(stream))
	{
		str = strcat("Error: Can't open file <file>", arg[1]);
		error_stack(str);
	}
	exit(EXIT_SUCCESS);
}
