#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	/*ft_printf("%i\n", argc);
	ft_printf("%s\n", argv[1]);
	ft_printf("%s\n", argv[2]);*/
	if(argc == 1)
		return(0);
	if(argc < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return(0);
	}
	i = 1;
	while (i < argc)
	{
		if (i ==1)
		{
			a = ft_lstnew (0);
			a = ft_lstnew (ft_atoi(argv[i], &a));
		}
		else
		{
		b = ft_lstnew (ft_atoi(argv[i], &a));
		ft_lstadd_back (&a, b);
		}
		i++;
	}
	if (check_dup(&a))
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(&a);
		return (0);
	}
	b = NULL;
	if (check_algo1(&a, &b))
	{
		ft_lstclear(&a);
		return (0);
	}
	if((argc - 1)  == 3)
		va_3(&a, &b);
	else if((argc - 1) <= 6)
		va_6(&a, &b, (argc - 1));
	else if((argc - 1) <= 12)
		va_12(&a, &b, (argc - 1));
	
	
	//run(&a, &b);
	ft_lstclear(&a);
}

void	va_6(t_stack **a, t_stack **b, int total)
{
	int	sm_a;
	int	sm_a2;
	int	a5;
	int	count;
	

	

	count = 1;
	sm_a2 = smallest2(a);
	while (count <= (total - 3))
	{
		a5 = ft_lstlast(*a)->data;
		sm_a = smallest(a);
		//ft_printf("%i_%i_%i\n", a5, sm_a, sm_a2);
	if(((*a)->data == sm_a || (*a)->data == sm_a2))
	{
		pb(a, b);
	}
	else if(a5 == sm_a || a5 == sm_a2)
	{
		rra(a);
		pb(a, b);
	}
	else if((*a)->next->data == sm_a || (*a)->next->data == sm_a2)
	{
		ra(a);
		pb(a, b);
	}
	else if((*a)->next->next->data == sm_a || (*a)->next->next->data == sm_a2)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	count++;
	}
	
	va_3(a, b);
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");
	ft_printf("%i\n", check_algo1(a, b));*/
	if (check_algo1(a, b))
	{
		algo_l(a, b);
	}
	else
	{
		while(check_algol(a, b, 0) == 0)
		{
				/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
			a5 = ft_lstlast(*a)->data;
			if((*b)->data < (*a)->data && (*b)->data < a5)
			{
				pa(b, a);
			}
			else if((*b)->data > a5 && (*b)->data < (*a)->data)
			{
				pa(b, a);
				rra(a);
			}
			else if((*b)->data < (*a)->next->data && (*b)->data > (*a)->data)
			{
				ra(a);
				pa(b, a);
				rra(a);
			}
			else if((*b)->data < a5 && (*b)->data < (*a)->data)
			{
				rra(a);
				pa(b, a);
			}
			else if((*b)->data < a5 && (*b)->data > (*a)->data)
			{
				pb(a, b);
				sb(b);
				rra(a);
				pa(b, a);
			}
			else if((*b)->data > a5 && (*b)->data > (*a)->data)
			{
				ra(a);
				pa(b, a);
				rra(a);
				rra(a);
			}
			va_3(a, b);
		}
	}
}

int	check_algol(t_stack **a, t_stack **b, int bleft)
{
	t_stack	*tmp;

	if (count_stack(b) > bleft)
		return (0);
	tmp = *a;
	while (tmp->next)
	{
	if (tmp->data < tmp->next->data)
		tmp = tmp->next;
	else
		return (0);
	}
	return (1);
}

int	largest(t_stack **stack)
{
	t_stack *tmp;
	int	lrg;
	
	lrg = (*stack)->data;
	tmp = (*stack)->next;
	while (tmp)
	{
		if(lrg < tmp->data)
			lrg = tmp->data;
		tmp = (tmp)->next;
	}
	return(lrg);
}

int	largest2(t_stack **stack)
{
	t_stack *tmp;
	int	lrg;
	int	lrg2;
	
	lrg = largest(stack);
	lrg2 = (*stack)->data;
	tmp = (*stack)->next;
	while (tmp)
	{
		if(lrg2 == lrg || (lrg2 < tmp->data && tmp->data < lrg))
			lrg2 = tmp->data;
		tmp = (tmp)->next;
	}
	return(lrg2);
}

int	smallest(t_stack **stack)
{
	t_stack *tmp;
	int	sm;
	
	sm = (*stack)->data;
	tmp = (*stack)->next;
	while (tmp)
	{
		if(sm > tmp->data)
			sm = tmp->data;
		tmp = (tmp)->next;
	}
	return(sm);
}

int	smallest2(t_stack **stack)
{
	t_stack *tmp;
	int	sm;
	int	sm2;
	
	sm = smallest(stack);
	sm2 = (*stack)->data;
	tmp = (*stack)->next;
	while (tmp)
	{
		if(sm2 == sm || (sm2 > tmp->data && tmp->data > sm))
			sm2 = tmp->data;
		tmp = (tmp)->next;
	}
	return(sm2);
}

void va_3(t_stack **a, t_stack	**b)
{
	int	a3;
	//t_stack *tmp;

	//tmp = ft_lstlast(*a);
		a3 = (*a)->next->next->data;

	if (count_stack(b) > 1)
	{
		if((*b)->next->data > (*b)->data)
		{
			if (a3 > (*a)->next->data  && (*a)->next->data > (*a)->data)
				sb(b);
			else if (a3 > (*a)->data && (*a)->data > (*a)->next->data)
				ss(a, b);
			else if ((*a)->next->data > a3 && a3 > (*a)->data)
			{
				rra(a);
				ss(a, b);
			}
			else if ((*a)->next->data > (*a)->data && (*a)->data > a3)
			{
				rra(a);
			}
			else if ((*a)->data > (*a)->next->data && (*a)->next->data > a3)
			{
				ra(a);
				ss(a, b);
			}
			else if ((*a)->data > a3 && a3 > (*a)->next->data)
				ra(a);
		}
			else
		{
			if (a3 > (*a)->next->data  && (*a)->next->data > (*a)->data)
				return ;
			else if (a3 > (*a)->data && (*a)->data > (*a)->next->data)
				sa(a);
			else if ((*a)->next->data > a3 && a3 > (*a)->data)
			{
				rra(a);
				sa(a);
			}
			else if ((*a)->next->data > (*a)->data && (*a)->data > a3)
			{
				rra(a);
			}
			else if ((*a)->data > (*a)->next->data && (*a)->next->data > a3)
			{
				ra(a);
				sa(a);
			}
			else if ((*a)->data > a3 && a3 > (*a)->next->data)
				ra(a);
		}
	}
	else
	{
		if (a3 > (*a)->next->data  && (*a)->next->data > (*a)->data)
			return ;
		else if (a3 > (*a)->data && (*a)->data > (*a)->next->data)
			sa(a);
		else if ((*a)->next->data > a3 && a3 > (*a)->data)
		{
			rra(a);
			sa(a);
		}
		else if ((*a)->next->data > (*a)->data && (*a)->data > a3)
		{
			rra(a);
		}
		else if ((*a)->data > (*a)->next->data && (*a)->next->data > a3)
		{
			ra(a);
			sa(a);
		}
		else if ((*a)->data > a3 && a3 > (*a)->next->data)
			ra(a);
	}
}

void va_3_mirr(t_stack **a, t_stack	**b)
{
	int	a3;
	//t_stack *tmp;

	//tmp = ft_lstlast(*a);
		a3 = (*a)->next->next->data;

	if (count_stack(a) > 1)
	{
		if((*b)->next->data < (*b)->data)
		{
			if (a3 < (*a)->next->data  && (*a)->next->data  < (*a)->data)
				sa(a);
			else if (a3 < (*a)->data && (*a)->data < (*a)->next->data)
				ss(a, b);
			else if ((*a)->next->data < a3 && a3 < (*a)->data)
			{
				rrb(b);
				ss(a, b);
			}
			else if ((*a)->next->data < (*a)->data && (*a)->data < a3)
			{
				rrb(b);
			}
			else if ((*a)->data < (*a)->next->data && (*a)->next->data < a3)
			{
				rb(b);
				ss(a, b);
			}
			else if ((*a)->data < a3 && a3 < (*a)->next->data)
				rb(b);
		}
			else
		{
			if (a3 < (*a)->next->data  && (*a)->next->data  < (*a)->data)
				sa(a);
			else if (a3 < (*a)->data && (*a)->data < (*a)->next->data)
				sb(b);
			else if ((*a)->next->data < a3 && a3 < (*a)->data)
			{
				rrb(b);
				sb(b);
			}
			else if ((*a)->next->data < (*a)->data && (*a)->data < a3)
			{
				rrb(b);
			}
			else if ((*a)->data < (*a)->next->data && (*a)->next->data < a3)
			{
				rb(b);
				sb(b);
			}
			else if ((*a)->data < a3 && a3 < (*a)->next->data)
				rb(b);
		}
	}
	else
	{
		if (a3 < (*a)->next->data  && (*a)->next->data  < (*a)->data)
			sa(a);
		else if (a3 < (*a)->data && (*a)->data < (*a)->next->data)
			sb(b);
		else if ((*a)->next->data < a3 && a3 < (*a)->data)
		{
			rrb(b);
			sb(b);
		}
		else if ((*a)->next->data < (*a)->data && (*a)->data < a3)
		{
			rrb(b);
		}
		else if ((*a)->data < (*a)->next->data && (*a)->next->data < a3)
		{
			rb(b);
			sb(b);
		}
		else if ((*a)->data < a3 && a3 < (*a)->next->data)
			rb(b);
	}
}

void	algo_l(t_stack **a, t_stack **b)
{
	while (*b)
		pa(b, a);
}

int	check_algo1(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (count_stack(b) > 0)
	{
		if ((*b)->data > (*a)->data)
			return (0);
		tmp = *b;
		while (tmp->next)
		{
		if (tmp->data > tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
		}
	}
	tmp = *a;
	while (tmp->next)
	{
	if (tmp->data < tmp->next->data)
		tmp = tmp->next;
	else
		return (0);
	}
	return (1);
}

int	check_dup(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;
	int		i;

	tmp2 = *a;
	while ((tmp2)->next)
	{
		i = (tmp2)->data;
		tmp = (tmp2)->next;
		while (tmp)
		{
			if (i == tmp->data)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			} 
			tmp = tmp->next;
		}
		tmp2 = (tmp2)->next;
	}
	return (0);	
}

