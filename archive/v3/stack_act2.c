#include "push_swap.h"

void ra(t_stack **a)
{
	t_stack	*tmp;

	if(count_stack(a) > 1)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_back(a, tmp);
	}
	ft_printf("ra\n");
}

void rb(t_stack **b)
{
	t_stack	*tmp;

	if(count_stack(b) > 1)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		ft_lstadd_back(b, tmp);
	}
	ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if(count_stack(a) > 1)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_back(a, tmp);
	}
	if(count_stack(b) > 1)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		ft_lstadd_back(b, tmp);
	}
	ft_printf("rr\n");
}

void rra(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;

	if(count_stack(a) > 1)
	{
		tmp = ft_lstlast(*a);
		tmp2 = *a;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next = NULL; 
		ft_lstadd_front(a, tmp);
	}
	ft_printf("rra\n");
}

void rrb(t_stack **b)
{
	t_stack *tmp;
	t_stack *tmp2;

	if(count_stack(b) > 1)
	{
	tmp = ft_lstlast(*b);
	tmp2 = *b;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL; 
	ft_lstadd_front(b, tmp);
	}
	ft_printf("rrb\n");
}