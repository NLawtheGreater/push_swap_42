#include "push_swap.h"

void	quick_2a(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	next;
	
	if (size <= 4)
	{
		sort_man_v2a(a, b, size);
		return ;
	}
	pb(a, b);
	pivot = (*b)->data;
	record = 1;
	next = 0;
	while(pivot_check(*a, pivot, size - record - next))
	{
		if((*a)->data > pivot)
		{	
			pb(a,b);
			record++;
		}
		else
		{
			ra(a);
			next++;
		}
	}
	while (next > 0)
	{
		rra(a);
			next--;
	}
	next = size - record;
	quick_2b(a, b, record);
	quick_2a(a, b, next);
}

void	quick_2b(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	next;
	
	if (size <= 4)
	{
		sort_man_v2b(a, b, size);
		return;
	}
	pa(b, a);
	pivot = (*a)->data;
	record = 1;
	next = 0;
	while(pivot_check(*b, pivot, size - record - next))
	{
		if((*b)->data > pivot)
		{	
			pa(b, a);
			record++;
		}
		else
		{
			rb(b);
			next++;
		}
		/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	}
	while (next > 0)
	{
		rrb(b);
		next--;
	}
	next = size - record;
	quick_2a(a, b, record);
	quick_2b(a, b, next);
}

int	pivot_check(t_stack *stack, int pivot, int size)
{
	while (size > 0)
	{
		if(stack->data > pivot)
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