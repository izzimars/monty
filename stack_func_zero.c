#include "main.h"

/**
 * push_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, (*cur_lst);

	(void)line_number;
	cur_lst = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_stack("Error: malloc failed");
	new_node->n = push_value;
	if (cur_lst == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		cur_lst = new_node;
		*stack = new_node;
	}
	else
	{
		new_node->next = cur_lst;
		cur_lst->prev = new_node;
		cur_lst = new_node;
		*stack = new_node;
	}
}

/**
 * pall_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pall_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst;
	char p;

	(void)line_number;
	cur_lst = *stack;
	if (cur_lst == NULL)
		return;
	while (cur_lst)
	{
		p = '0' + cur_lst->n;
		printf("%c\n", p);
		cur_lst = cur_lst->next;
	}
}
