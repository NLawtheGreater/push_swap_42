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
	i = 1;
	while (i < argc)
	{
		if (i ==1)
		{
			a = 0;
			a = ft_lstnew (ft_atoi(argv[i], &a));
		}
		else
		{
		b = ft_lstnew (ft_atoi(argv[i], &a));
		ft_lstadd_back (&a, b);
		}
		i++;
	}
	if (count_stack(&a)  == 1)
	{	
		ft_lstclear(&a);
		return (0);
	}
	if (check_dup(&a))
	{
		ft_lstclear(&a);
		return (0);
	}
	b = NULL;
	
	if (count_stack(&a)  >= 2 && count_stack(&a)  <= 5)
		sort_man(&a, &b);
	else if (count_stack(&a)  >= 6 && count_stack(&a)  <= 40)
		sort_insrt(&a, &b);
	else if (count_stack(&a)  >= 41)
		sort_quick(&a, &b);

	ft_lstclear(&a);
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

void sort_man(t_stack **a, t_stack **b)
{
	if (count_stack(a) == 2)
	{
		if ((*a)->data < (*a)->next->data)
			return;
		else if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else
	{
		if(!check_stack(a, 'a'))
		{
			sort_man5(a, b);
			sort_man3(a);
			if((*b)->data < (*b)->next->data)
				sb(b);
			pa(b, a);
			pa(b, a);
		}
	}
}

void	sort_man5(t_stack **a, t_stack **b)
{
	int	seq;
	int	count;

	while(count_stack(a) > 3)
	{
		/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
		seq = find_tar_s(a);
		if(seq <= count_stack(a) + 1)
		{
			count = 1;
			while (count < seq)
			{
				ra(a);
				count++;
			}
			pb(a, b);	
		}
		else
		{
			count = 0;
			while (count <= (count_stack(a) - seq))
			{
				rra(a);
				count++;
			}
			pb(a, b);	
		}
		
	}
}
void	sort_man3(t_stack **a)
{
	int	a3;

	a3 = (*a)->next->next->data;
	if ((*a)->data < (*a)->next->data  && (*a)->next->data < a3)
			return ;
	else if ((*a)->next->data < (*a)->data  && (*a)->data < a3)
		sa(a);
	//check for sort_quick
	else if ((*a)->data < a3 && a3 < (*a)->next->data)
	{
		rra(a);
		sa(a);
	}
	//check for sort_quick
	else if (a3 < (*a)->data && (*a)->data < (*a)->next->data)
		rra(a);
	//check for sort_quick
	else if (a3 < (*a)->next->data && (*a)->next->data < (*a)->data)
	{
		ra(a);
		sa(a);
	}
	//check for sort_quick
	else if ((*a)->next->data < a3 && a3 < (*a)->data)
		ra(a);
}