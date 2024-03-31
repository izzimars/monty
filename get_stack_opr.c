#include "main.h"

/**
 * get_stack_opt- returns the amount of identifiers.
 * @p: argument indentifier
 *
 * Return: amount of identifiers.
 */
void (*get_stack_opt(char *p))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t lst[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"add", padd_stack},
		{"sub", psub_stack},
		{"nop", pnop_stack},
		{NULL, NULL}
	};
	while (lst[i].opcode)
	{
		if (strcmp(p, lst[i].opcode) == 0)
			return (lst[i].f);
		else
			++i;
	}
	return (NULL);
}
