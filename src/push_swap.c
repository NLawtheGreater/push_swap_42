#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	//int		j;
	t_stack	*a;
	t_stack	*b;

	if(argc == 1)
		return (0);
	if(argc < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	i = 1;
	//j = 0;
	while (i < argc)
	{
		/*while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("Error\n", 2);
				ft_lstclear(&a);
				return (0);
			}
			j++;
		}*/
		//design oversize and non-int trap here
		if (i ==1)
			a = ft_lstnew (ft_atoi(argv[i]));
		else
		{
		b = ft_lstnew (ft_atoi(argv[i]));
		ft_lstadd_back (&a, b);
		}
		i++;
	}
	if (check_dup(&a))
	{
		ft_lstclear(&a);
		return (0);
	}
	b = NULL;
	if(count_stack(&a) == 3)
		va_3(&a);
	if(count_stack(&a) == 5)
		va_5(&a, &b);
	//run(&a, &b);
	ft_lstclear(&a);
}

void	va_5(t_stack **a, t_stack **b)
{
	int	sm_a;
	int	sm_a2;
	int	a5;
	

	sm_a = smallest(a);
	sm_a2 = smallest2(a);
	a5 = ft_lstlast(*a)->data;

	if(((*a)->data == sm_a2 && a5 == sm_a) ||\
	((*a)->data == sm_a && a5 == sm_a2))
	{
		pb(a, b);
		rra(a);
		pb(a, b);
	}
	else if(((*a)->next->data == sm_a2 && a5 == sm_a) ||\
	((*a)->next->data == sm_a && a5 == sm_a2))
	{
		sa(a);
		pa(b, a);
		ra(a);
		pa(b, a);
	}
	else if((*a)->data == sm_a)
	{
		pb(a, b);
		pb(a, b);
	}
	else if((*a)->next->data == sm_a)
	{
		pb(a, b);
		pb(a, b);
	}
	else if(a5 == sm_a)
	{
		rra(a);
		pb(a, b);
		pb(a, b);
	}
	va_3(a);
	if (check_algo1(a, b))
	{
		pa(b, a);
		pa(b, a);
	}
	else
	{
		while(!check_algol())
		{
			if((*b)->data < (*a)->data && (*b)->data < a5)
				pa(b, a);
			else if((*b)->data < (*a)->next->data && (*b)->data > (*a)->data)
			{
				ra(a);
				pa(b, a);
			}
			else if((*b)->data > a5 && (*b)->data < (*a)->data)
			{
				pa(b, a);
				rra(a);
			}
			else if((*b)->data < a5 && (*b)->data < (*a)->data)
			{
				rra(a);
				pa(b, a);
			}
		}
	}
}

void va_3(t_stack **a)
{
	int	a3;
	t_stack *tmp;

	tmp = ft_lstlast(*a);
		a3 = tmp->data;
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
	{
		ra(a);
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

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new)
	{
		if (!lst)
		{
			*lst = new;
			return ;
		}
		new->next = *lst;
		*lst = new;
	}
}

/*t_stack	*commence ()
{
	t_stack	*a;

	a = (t_stack*) malloc(sizeof(t_stack));
	ft_lstnew()

}*/


t_stack	*ft_lstnew(int data)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	lst_check(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
	return;
	tmp = *lst;
	while (tmp != NULL)
	{
		ft_printf("%i\n", tmp->data);		
		tmp = tmp->next;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;

	if (!*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free (*lst);
		*lst = ptr;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_stack **lst)
{
	t_stack	*ptr;

	ptr = (*lst)->next;
	free(*lst);
	*lst = ptr;
}
