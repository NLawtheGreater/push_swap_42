#include "push_swap.h"

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
	if((argc - 1)  == 3)
		va_3(&a, &b);
	if((argc - 1) <= 6)
		va_5(&a, &b, (argc - 1));
	//run(&a, &b);
	ft_lstclear(&a);
}

void	va_5(t_stack **a, t_stack **b, int total)
{
	int	sm_a;
	int	sm_a2;
	int	a5;
	int	count;
	

	
	a5 = ft_lstlast(*a)->data;

	sm_a = smallest(a);
	sm_a2 = smallest2(a);
	count = 1;
	while (count <= (total - 3))
	{
	if (count == 3)
		sm_a = smallest(a);
	if(((*a)->data == sm_a || (*a)->data == sm_a2))
	{
		pb(a, b);
	}
	else if(a5 == sm_a || a5 == sm_a2)
	{
		rra(a);
		pa(b, a);
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
	
	ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");
	va_3(a, b);
	if (check_algo1(a, b))
	{
		pa(b, a);
		pa(b, a);
	}
	else
	{
		while(check_algol(a, b) == 0)
		{
				ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");
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