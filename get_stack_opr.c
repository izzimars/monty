#include "main.h"

/**
 * get_stack_opt- returns the amount of identifiers.
 * @p: argument indentifier
 *
 * Return: amount of identifiers.
 */
void (*get_stack_opt(char *p))(stack_t **stack, unsigned int line_number)
{
	int i = 0, j = 0;
	instruction_t lst[] = {
		{"push", push_stack},
		{"pall", pall_stack}
	};
	while (lst[i].opcode)
	{
		if (p[j] == lst[i].opcode[j])
		{
			if (p[j] == '\0')
				return (lst[i].f);
			++j;
		}
		else
		{
			++i;
			j = 0;
		}
	}
	return (NULL);
}
