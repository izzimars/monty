#include "main.h"
/**
 * pchar_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pchar_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst;
	char str[50];

	(void)line_number;
	cur_lst = *stack;
	if (cur_lst == NULL)
	{
		sprintf(str, "L%d: can't pchar, stack empty\n", line_number);
		error_stack(str);
	}
	if (cur_lst->n >= 0 && cur_lst->n <= 127)
		printf("%c\n", (char)cur_lst->n);
	else
	{
		sprintf(str, "L%d: can't pchar, value out of range\n", line_number);
		error_stack(str);
	}
}

/**
 * pstr_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst;
	char str[50], newstr[50];

	(void)line_number;
	cur_lst = *stack;
	if (cur_lst == NULL)
		printf("\n"):
	while (cur_lst != NULL)
	{
		if (cur_lst->n >= 0 && cur_lst->n <= 127)
			break;
	}
		printf("%c\n", (char)cur_lst->n);
	else
	{
		sprintf(str, "L%d: can't pchar, value out of range\n", line_number);
		error_stack(str);
	}
}
