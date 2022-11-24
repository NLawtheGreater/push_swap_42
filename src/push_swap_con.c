/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_con.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:09:23 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 21:09:26 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man5_con(t_stack **a, t_stack **b, int seq)
{
	int	count;

	if (seq <= count_stack(a) / 2 + 1)
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

void	sort_man3(t_stack **a)
{
	int	a3;

	a3 = (*a)->next->next->data;
	if ((*a)->data < (*a)->next->data && (*a)->next->data < a3)
		return ;
	else if ((*a)->next->data < (*a)->data && (*a)->data < a3)
		sa(a);
	else if ((*a)->data < a3 && a3 < (*a)->next->data)
	{
		rra(a);
		sa(a);
	}
	else if (a3 < (*a)->data && (*a)->data < (*a)->next->data)
		rra(a);
	else if (a3 < (*a)->next->data && (*a)->next->data < (*a)->data)
	{
		ra(a);
		sa(a);
	}
	else if ((*a)->next->data < a3 && a3 < (*a)->data)
		ra(a);
}
