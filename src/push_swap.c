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
	if (count_stack(&a)  == 1)
		return (0);
	if (check_dup(&a))
	{
		ft_lstclear(&a);
		return (0);
	}
	b = NULL;
	
	
	
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