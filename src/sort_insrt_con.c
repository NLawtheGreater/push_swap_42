/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insrt_con.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:42:03 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 21:42:05 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_insrt2_con2(t_stack **a, t_stack **b, int seq)
{
	int	count;

	count = -1;
	while (count < (count_stack(a) - seq))
	{
		rra(a);
		count++;
	}
	pa(b, a);
	while (count > -2)
	{
		ra(a);
		count--;
	}
}

int	check_stack(t_stack **stack, char x)
{
	t_stack	*tmp;

	if (count_stack(stack) == 0)
		return (1);
	tmp = *stack;
	if (x == 'b')
	{
		while (tmp->next)
		{
			if (tmp->data > tmp->next->data)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	else if (x == 'a')
	{
		if (check_stack_con(tmp) == 0)
			return (0);
	}
	return (1);
}

int	check_stack_con(t_stack *tmp)
{
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
