#include "main.h"

/**
 * pnop_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pnop_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * psub_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void psub_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst;
	char str[50];
	int i =0, sum = 0;

	cur_lst = *stack;
	while (cur_lst != NULL)
	{
		if (i == 0)
			sum -= cur_lst->n;
		else
		{
			sum += cur_lst->n;
			i++;
			break;
		}
		i++;
		cur_lst = cur_lst->next;
	}
	if (i != 2)
	{
		sprintf(str, "L%d: can't sub, stack too short\n", line_number);
		error_stack(str);
	}
	*stack = cur_lst;
	(*stack)->n = sum;
	cur_lst = cur_lst->prev;
	(*stack)->prev = NULL;
	free(cur_lst);
}

/**
 * pdiv_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pdiv_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst, (*next);
	char str[50];

	cur_lst = *stack;
	next = cur_lst->next;
	if (cur_lst != NULL && next != NULL)
	{
		if (next == 0)
		{
			sprintf(str, "L%d: division by zero\n", line_number);
			error_stack(str);
		}
		next->n = next->n / cur_lst->n;
		*stack = next;
		(*stack)->prev = NULL;
		free(cur_lst);
	}
	else
	{
		sprintf(str, "L%d: can't div, stack too short\n", line_number);
		error_stack(str);
	}
}

/**
 * pmul_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pmul_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst, (*next);
	char str[50];

	cur_lst = *stack;
	next = cur_lst->next;
	if (cur_lst != NULL && next != NULL)
	{
		next->n = next->n * cur_lst->n;
		*stack = next;
		(*stack)->prev = NULL;
		free(cur_lst);
	}
	else
	{
		sprintf(str, "L%d: can't mul, stack too short\n", line_number);
		error_stack(str);
	}
}

/**
 * pmod_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pmod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst, (*next);
	char str[50];

	cur_lst = *stack;
	next = cur_lst->next;
	if (cur_lst != NULL && next != NULL)
	{
		if (next == 0)
		{
			sprintf(str, "L%d: division by zero\n", line_number);
			error_stack(str);
		}
		next->n = next->n % cur_lst->n;
		*stack = next;
		(*stack)->prev = NULL;
		free(cur_lst);
	}
	else
	{
		sprintf(str, "L%d: can't mod, stack too short\n", line_number);
		error_stack(str);
	}
}
