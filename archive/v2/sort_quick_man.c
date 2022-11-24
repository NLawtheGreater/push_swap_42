#include "push_swap.h"

void sort_man_v2a(t_stack **a, t_stack **b, int size)
{
	//check for next version
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	if (size == 2)
	{
		 if ((*a)->data < (*a)->next->data)
			sa(a);
	}
	else if (size >= 3)
	{
			size = sort_man3_v2a(a, b, size);
	}
	while (size > 0)
	{
		if (count_stack(a) > 0)
		{
		pb(a, b);
		rb(b);
		}
		size--;
	}
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
}

int	sort_man3_v2a(t_stack **a, t_stack	**b, int size)
{
	int	a3;

	a3 = (*a)->next->next->data;
	if ((*a)->data > (*a)->next->data  && (*a)->next->data > a3)
			return (size);
	else if ((*a)->next->data > (*a)->data  && (*a)->data > a3)
		sa(a);
	else if ((*a)->data > a3 && a3 > (*a)->next->data)
	{
		pb(a, b);
		sa(a);
		rb(b);
		size -= 1;
		//
	}
	else if (a3 > (*a)->data && (*a)->data > (*a)->next->data)
		{
			pb(a, b);
			sa(a);
			pa(b, a);
			sa(a);
		}
	else if (a3 > (*a)->next->data && (*a)->next->data > (*a)->data)
	{
		sa(a);
			ra(a);
			sa(a);
			rra(a);
			sa(a);
	}
	else if ((*a)->next->data > a3 && a3 > (*a)->data)
		{
			sa(a);
			ra(a);
			sa(a);
			rra(a);
		}
	return (size);
}

void sort_man_v2b(t_stack **a, t_stack **b, int size)
{
	//check for next version
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	if (size == 2)
	{
		if ((*b)->data < (*b)->next->data)
			sb(b);
	}
	else if (size >= 3)
	{
			size = sort_man3_v2b(a, b, size);
	}
	while (size > 0)
	{
		rb(b);
		size--;
	}
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
}

int	 sort_man3_v2b(t_stack **a, t_stack	**b, int size)
{
	int	b3;

	b3 = (*b)->next->next->data;
	if ((*b)->data > (*b)->next->data  && (*b)->next->data > b3)
			return (size);
	else if ((*b)->next->data > (*b)->data  && (*b)->data > b3)
		sb(b);
	else if ((*b)->data > b3 && b3 > (*b)->next->data)
	{
		pa(b, a);
		sb(b);
		pb(a, b);
	}
	else if (b3 > (*b)->data && (*b)->data > (*b)->next->data)
		{
			pa(b, a);
			sb(b);
			pb(a, b);
			sb(b);
		}
	else if (b3 > (*b)->next->data && (*b)->next->data > (*b)->data)
	{
					sb(b);
			rb(b);
			sb(b);
			rrb(b);
			sb(b);
	}
	else if ((*b)->next->data > b3 && b3 > (*b)->data)
		{
			sb(b);
			rb(b);
			sb(b);
			size -= 1;
			// rrb(b);
		}
	return (size);
}