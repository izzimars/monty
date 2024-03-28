#include "main.h"
/* stack_error: Prints our error to the standard output.
 *
 * @s: a char[], error message.
 * @i: line number where error was found.
 * @opcode: opcode of the line.
 *
 * return: None
 */
void error_stack(char *s)
{
	write(2, s, strlen(s));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
