#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - Does nothing
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}
