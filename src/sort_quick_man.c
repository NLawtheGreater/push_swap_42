/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:33:22 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:33:23 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man_v2a(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else if (size == 3 || (size == 4 && man_check(*a, 4)))
	{
			size = sort_man3_v2a(a, b, size);
	}
	else if (size >= 4)
	{
		size = sort_man4_a(a, b, size);
	}
	while (size > 0)
	{
		ra(a);
		size--;
	}
}

int	sort_man3_v2a(t_stack **a, t_stack	**b, int size)
{
	int	a3;

	a3 = (*a)->next->next->data;
	if ((*a)->data < (*a)->next->data && (*a)->next->data < a3)
		return (size);
	else if ((*a)->next->data < (*a)->data && (*a)->data < a3)
		sa(a);
	else if ((*a)->data < a3 && a3 < (*a)->next->data)
	{
		sort_man3_v2a_1(a, &size);
	}
	else if (a3 < (*a)->data && (*a)->data < (*a)->next->data)
	{
		sort_man3_v2a_2(a, b, &size);
	}
	else if (a3 < (*a)->next->data && (*a)->next->data < (*a)->data)
	{
		sort_man3_v2a_3(a, b, &size);
	}
	else if ((*a)->next->data < a3 && a3 < (*a)->data)
	{
		sort_man3_v2a_4(a, b, &size);
	}
	return (size);
}

void	sort_man3_v2a_1(t_stack **a, int *size)
{
	ra(a);
	sa(a);
	*size -= 1;
}

void	sort_man3_v2a_2(t_stack **a, t_stack **b, int *size)
{
	pb(a, b);
	sa(a);
	ra(a);
	pa(b, a);
	*size -= 1;
}

void	sort_man3_v2a_3(t_stack **a, t_stack **b, int *size)
{
	pb(a, b);
	sa(a);
	ra(a);
	ra(a);
	pa(b, a);
	*size -= 2;
}
