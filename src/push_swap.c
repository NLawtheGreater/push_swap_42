/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:32:41 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:32:43 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* Version 5
 Possible: 		error with INT MAX
 add: 			median test (got 4 points territory)
 Optimisable:	5 int sometimes needs 10 moves.  Possible to change to 1 out, 
 then sort 4 function.
 Uncompleted: 	Norminette*/

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (i == 1)
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
	b = NULL;
	return (main_con(&a, &b));
}

int	main_con(t_stack **a, t_stack **b)
{
	if (count_stack(a) == 1)
	{	
		ft_lstclear(a);
		return (1);
	}
	check_dup(a);
	if (check_stack(a, 'a'))
	{
		ft_lstclear(a);
		return (0);
	}
	if (count_stack(a) >= 2 && count_stack(a) <= 5)
		sort_man(a, b);
	else if (count_stack(a) >= 6 && count_stack(a) <= 40)
		sort_insrt(a, b);
	else if (count_stack(a) >= 41)
		sort_quick(a, b);
	ft_lstclear(a);
	return (0);
}

int	check_dup(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
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
				ft_lstclear(a);
				exit(1);
			}
			tmp = tmp->next;
		}
		tmp2 = (tmp2)->next;
	}
	return (0);
}

void	sort_man(t_stack **a, t_stack **b)
{
	if (count_stack(a) == 2)
	{
		if ((*a)->data < (*a)->next->data)
			return ;
		else if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else
	{
		sort_man5(a, b);
		sort_man3(a);
		if (count_stack(b) == 2)
		{
			if ((*b)->data < (*b)->next->data)
				sb(b);
			pa(b, a);
		}
		pa(b, a);
	}
}

void	sort_man5(t_stack **a, t_stack **b)
{
	int	seq;

	while (count_stack(a) > 3)
	{
		seq = find_tar_s(a);
		sort_man5_con(a, b, seq);
	}
}
