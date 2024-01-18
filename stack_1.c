#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * Return: nothing
*/

void swap(lstack_t **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return;
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - add two elements of the stack
 * @lstack_t: the stack
 * Return: nothing
*/

void add(lstack_t **lstack_t)
{
	int sum;

	sum = (*lstack_t)->n + (*lstack_t)->next->n;
	pop(lstack_t);
	(*lstack_t)->n = sum;
}
