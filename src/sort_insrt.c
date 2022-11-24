/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:34:11 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:34:13 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_insrt(t_stack **a, t_stack	**b)
{
	int	count;
	int	seq;

	while (count_stack(a) > 3)
	{
		if ((*a)->next->data < (*a)->data)
			sa(a);
		seq = e1_into_stack(a, b, 'a');
		count = 1;
		while (count < seq)
		{
			rb(b);
			count++;
		}
		pb(a, b);
		while (count > 1)
		{
			rrb(b);
			count--;
		}	
	}
	sort_insrt2(a, b);
}

int	e1_into_stack(t_stack **a, t_stack **b, char x)
{
	t_stack	*tmp;
	int		seq;

	seq = 1;
	if (x == 'a')
	{
		tmp = *b;
		while (tmp)
		{
			if (count_stack(b) == 1)
				break ;
			if ((*a)->data > tmp->data)
				break ;
			tmp = (tmp)->next;
			seq++;
		}
	}
	else if (x == 'b')
	{
		tmp = *a;
		e1_into_stack_con(a, b, tmp, &seq);
	}
	return (seq);
}

void	e1_into_stack_con(t_stack **a, t_stack **b, t_stack *tmp, int *ptr)
{
	while (tmp)
	{
		if (count_stack(a) == 1)
			break ;
		if ((*b)->data < tmp->data)
			break ;
		tmp = (tmp)->next;
		*ptr += 1;
	}
}

void	sort_insrt2(t_stack **a, t_stack	**b)
{
	int	seq;

	sort_man3(a);
	while (count_stack(b) > 0)
	{
		seq = e1_into_stack(a, b, 'b');
		if (seq <= (count_stack(a) / 2))
		{
			sort_insrt2_con(a, b, seq);
		}
		else
		{
			sort_insrt2_con2(a, b, seq);
		}
	}
}

void	sort_insrt2_con(t_stack **a, t_stack **b, int seq)
{
	int	count;

	count = 1;
	while (count < seq)
	{
		ra(a);
		count++;
	}
	pa(b, a);
	while (count > 1)
	{
		rra(a);
		count--;
	}	
}
