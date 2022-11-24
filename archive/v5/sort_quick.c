#include "push_swap.h"

void	sort_quick(t_stack **a, t_stack	**b)
{
	quick_a(a, b, count_stack(a));
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
}

void	quick_a(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	next;
	
	pivot = find_median(*a, size);
	//ft_printf("%i\n", pivot);
	record = 0;
	while(pivot_check(*a, pivot, size - record))
	{
		if((*a)->data <= pivot)
		{	
			pb(a,b);
			record++;
		}
		else
			ra(a);
		
	}
	next = size - record;
	quick_b(a, b, record);
	quick_1a(a, b, next);
}

void	quick_b(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	record;
	int	next;
	
	if (size < 5 || (size == 5 && man_check(*b, 5)))
	{
		sort_man_v2b(a, b, size);
		return;
	}
	pivot = find_median(*b, size);
	//ft_printf("%i\n", pivot);
	record = 0;
	while(pivot_check(*b, pivot, size - record))
	{
		if((*b)->data <= pivot)
		{	
			pa(b,a);
			record++;
		}
		else
			rb(b);
	}
	next = size - record;
	quick_1a(a, b, record);
	quick_1b(a, b, next);
}

void	quick_1a(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	next;
	
	if (size < 5 || (size == 5 && man_check(*a, 5)))
	{
		sort_man_v2a(a, b, size);
		return ;
	}
	pivot = find_median(*a, size);
	//ft_printf("%i\n", pivot);
	record = 0;
	next = 0;
	while(pivot_check(*a, pivot, size - record - next))
	{
		if((*a)->data <= pivot)
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
	quick_1b(a, b, record);
	quick_1a(a, b, next);
}

void	quick_1b(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	next;
	
	if (size < 5 || (size == 5 && man_check(*b, 5)))
	{
		sort_man_v2b(a, b, size);
		return;
	}
	pivot = find_median(*b, size);
	//ft_printf("%i\n", pivot);
	record = 0;
	next = 0;
	while(pivot_check(*b, pivot, size - record - next))
	{
		if((*b)->data <= pivot)
		{	
			pa(b, a);
			record++;
		}
		else
		{
			rb(b);
			next++;
		}
	}
	while (next > 0)
	{
		rrb(b);
		next--;
	}
	next = size - record;
	quick_1a(a, b, record);
	quick_1b(a, b, next);
}
