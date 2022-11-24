#include "push_swap.h"

void	sort_quick(t_stack **a, t_stack	**b)
{
	quick_a(a, b, count_stack(a));
	fin_quick(a, b);
}

void	quick_a(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	next;
	
	if (size <= 4)
	{
		sort_man_v2a(a, b, size);
		return;
	}
	pb(a, b);
	pivot = (*b)->data;
	record = 1;
	while(pivot_check(*a, pivot, size - record))
	{
		if((*a)->data > pivot)
		{	
			pb(a,b);
			record++;
		}
		else
			ra(a);
		
	}
	next = size - record;
	quick_b(a, b, record);
	quick_2a(a, b, next);
}

void	quick_b(t_stack **a, t_stack **b, int size)
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
	while(pivot_check(*b, pivot, size - record))
	{
		if((*b)->data > pivot)
		{	
			pa(b,a);
			record++;
		}
		else
			rb(b);
	}
	next = size - record;
	quick_1a(a, b, record);
	quick_2b(a, b, next);
}

void	quick_1a(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	record_bot;
	int	next;
	
	if (size <= 4)
	{
		sort_man_v2a(a, b, size);
		return;
	}
	pb(a, b);
	pivot = (*b)->data;
	record = 1;
	record_bot = 0;
	while(pivot_check(*a, pivot, size - record - record_bot))
	{
		if((*a)->data > pivot)
		{	
			pb(a,b);
			record++;
		}
		else
		{
			ra(a);
			record_bot++;
		}
	}
	while (record_bot > 0)
	{
		rra(a);
		record_bot--;
	}
	next = size - record;
	quick_1b(a, b, record);
	quick_2a(a, b, next);
}

void	quick_1b(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	record_bot;
	int	next;
	
	if (size <= 4)
		{
		sort_man_v2b(a, b, size);
		return;
		}
	pa(b, a);
	pivot = (*a)->data;
	record = 1;
	record_bot = 0;
	while(pivot_check(*b, pivot, size - record - record_bot))
	{
		if((*b)->data > pivot)
		{	
			pa(b,a);
			record++;
		}
		else
		{
			rb(b);
		record_bot++;
		}
	}
	while (record_bot > 0)
	{
		rrb(b);
		record_bot--;
	}
	next = size - record;
	quick_1a(a, b, record);
	quick_2b(a, b, next);
}
