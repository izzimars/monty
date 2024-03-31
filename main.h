#ifndef _LISTS_
#define _LISTS_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int push_value;
void (*get_stack_opt(char *p))(stack_t **stack, unsigned int line_number);
void error_stack(char *s);
void push_stack(stack_t **stack, unsigned int line_number);
void pall_stack(stack_t **stack, unsigned int line_number);
void pint_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void padd_stack(stack_t **stack, unsigned int line_number);
void psub_stack(stack_t **stack, unsigned int line_number);
void pnop_stack(stack_t **stack, unsigned int line_number);
void pdiv_stack(stack_t **stack, unsigned int line_number);
char *str_concat(int i, char *fori);
void line_arr(char *str,char **strarr);


#endif
