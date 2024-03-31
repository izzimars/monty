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

	(void)line_number;
	cur_lst = *stack;
	if (cur_lst == NULL)
		return;
	while (cur_lst)
	{
		printf("%d\n", cur_lst->n);
		cur_lst = cur_lst->next;
	}
}

/**
 * pint_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pint_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst;

	(void)line_number;
	cur_lst = *stack;
	if (cur_lst == NULL)
		return;
	printf("%d\n", cur_lst->n);
}

/**
 * pop_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst;
	char str[50];

	(void)line_number;
	cur_lst = *stack;
	if (cur_lst == NULL)
	{
		str[0] = 'L';
		sprintf(str + 1, "%d", line_number);
		strcat(str, ": can't pop an empty stack\n");
		error_stack(str);
	}
	while (cur_lst->prev != NULL)
		cur_lst = cur_lst->prev;
	if (cur_lst->next == NULL)
		*stack = NULL;
	else
	{
		*stack = cur_lst->next;
		(*stack)->prev = NULL;
	}
	free(cur_lst);
}
/**
 * padd_stack - opcode and its function
 * Description: Function that push a int to a stack.
 *
 * @stack: the stack containing integers
 * @line_number: The current file line being processed.
 *
 * Return: None
 */
void padd_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cur_lst;
	char str[50];
	int i =0, sum = 0;

	cur_lst = *stack;
	while (cur_lst != NULL)
	{
		sum += cur_lst->n;
		i++;
		if (i == 2)
			break;
		cur_lst = cur_lst->next;
	}
	if (i != 2)
	{
		sprintf(str, "L%d: can't add, stack too short\n", line_number);
		error_stack(str);
	}
	*stack = cur_lst;
	(*stack)->n = sum;
	cur_lst = cur_lst->prev;
	(*stack)->prev = NULL;
	free(cur_lst);
}
