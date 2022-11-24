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
		 if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	/*else if (size == 4 && (*a)->next->next->next->data < (*a)->data)  
	{

	}*/
	else if (size >= 3)
	{
			size = sort_man3_v2a(a, b, size);
	}
	while (size > 0)
	{
		ra(a);
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
	if ((*a)->data < (*a)->next->data  && (*a)->next->data < a3)
			return (size);
	else if ((*a)->next->data < (*a)->data  && (*a)->data < a3)
		sa(a);
	else if ((*a)->data < a3 && a3 < (*a)->next->data)
	{
		ra(a);
		sa(a);
		size -= 1;
		//
	}
	else if (a3 < (*a)->data && (*a)->data < (*a)->next->data)
		{
			pb(a, b);
			sa(a);
			ra(a);
			pa(b, a);
			size -= 1;
		}
	else if (a3 < (*a)->next->data && (*a)->next->data < (*a)->data)
	{
			pb(a, b);
			sa(a);
			ra(a);
			ra(a);
			pa(b, a);
			size -= 2;
	}
	else if ((*a)->next->data < a3 && a3 < (*a)->data)
		{
			pb(a, b);
			ra(a);
			ra(a);
			pa(b, a);
			size -= 2;
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
	if (size == 2 && ((*b)->data > (*b)->next->data))
	{
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 2;
	}
	else if (size >= 3)
	{
			sort_man3_v2b(a, b);
			size -= 3;
	}
	while (size > 0)
	{
		pa(b, a);
		ra(a);
		size--;
	}
	
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
}

void	 sort_man3_v2b(t_stack **a, t_stack	**b)
{
	int	b3;

	b3 = (*b)->next->next->data;
	if ((*b)->data < (*b)->next->data  && (*b)->next->data < b3)
		{
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
		}
	else if ((*b)->next->data < (*b)->data  && (*b)->data < b3)
		{
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			pa(b, a);
			ra(a);
		}
	else if ((*b)->data < b3 && b3 < (*b)->next->data)
	{
		pa(b, a);
		ra(a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
	}
	else if (b3 < (*b)->data && (*b)->data < (*b)->next->data)
		{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			sa(a);
			ra(a);
			ra(a);
		}
	else if (b3 < (*b)->next->data && (*b)->next->data < (*b)->data)
	{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			ra(a);
	}
	else if ((*b)->next->data < b3 && b3 < (*b)->data)
		{
			pa(b, a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			ra(a);
		}
}