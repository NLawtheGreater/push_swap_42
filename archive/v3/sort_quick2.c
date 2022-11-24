#include "push_swap.h"

int	pivot_check(t_stack *stack, int pivot, int size)
{
	while (size > 0)
	{
		if(stack->data < pivot)
			return (1);
		stack = stack->next;
		size--;
	}
	return (0);
}

void	fin_quick(t_stack **a, t_stack	**b)
{
	while(count_stack(b) != 0)
	{
		if((*b)->data == extreme(b, 'l'))
			pa(b, a);
		else
			rb(b);
	}
}