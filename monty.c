#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 * @argc: number of command line arguments.
 * @argv: array that contains the program command line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *arg[])
{
	int i = 1, n = 500;
	char *str, (* opcode), (*lineptr) = NULL, p;
	FILE *stream;
	void (*stack_function)(stack_t **, unsigned int);
	stack_t *lst = NULL;

	printf("aaaaaaaaaaaaa");
	if (argc != 2)
		error_stack("USAGE: monty file");
	printf("bbbbbbbbbbbbbbbbbb");
	stream = fopen(arg[1], "r");
	if (stream == NULL)
	{
		str = strcat("Error: Can't open file", arg[1]);
		error_stack(str);
	}
	printf("cccccccccccccc");
	while(fgets(lineptr, n, stream) != NULL)
	{
		str = strtok(lineptr, " ");
		opcode = strtok(NULL, " ");
		push_value = atoi(strtok(NULL, " "));
		stack_function = get_stack_opt(opcode);
		if (stack_function == NULL)
		{
			free(lineptr);
			p = '0' + i;
			str = strcat("L", &p);
			str = strcat(str, ": unknown instruction ");
			str = strcat(str, opcode);
			error_stack(str);
		}
		else
			stack_function(&lst, push_value);
		i++;
	}
	printf("ddddddddddddddd");
	free(lineptr);
	if (ferror(stream))
	{
		str = strcat("Error: Can't open file <file>", arg[1]);
		error_stack(str);
	}
	exit(EXIT_SUCCESS);
}
