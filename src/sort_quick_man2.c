/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:05:37 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 22:05:38 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man3_v2a_4(t_stack **a, t_stack **b, int *size)
{
	pb(a, b);
	ra(a);
	ra(a);
	pa(b, a);
	*size -= 2;
}

void	sort_man_v2b(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && ((*b)->data > (*b)->next->data))
	{
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		size -= 2;
	}
	else if (size == 3 || (size == 4 && man_check(*b, 4)))
	{
		sort_man3_v2b(a, b);
		size -= 3;
	}
	else if (size >= 4)
	{
		size = sort_man4_b(a, b, size);
	}
	while (size > 0)
	{
		pa(b, a);
		ra(a);
		size--;
	}
}

void	sort_man3_v2b(t_stack **a, t_stack	**b)
{
	int	b3;

	b3 = (*b)->next->next->data;
	if ((*b)->data < (*b)->next->data && (*b)->next->data < b3)
		sort_man3_v2b_1(a, b);
	else if ((*b)->next->data < (*b)->data && (*b)->data < b3)
		sort_man3_v2b_2(a, b);
	else if ((*b)->data < b3 && b3 < (*b)->next->data)
		sort_man3_v2b_3(a, b);
	else if (b3 < (*b)->data && (*b)->data < (*b)->next->data)
		sort_man3_v2b_4(a, b);
	else if (b3 < (*b)->next->data && (*b)->next->data < (*b)->data)
		sort_man3_v2b_5(a, b);
	else if ((*b)->next->data < b3 && b3 < (*b)->data)
		sort_man3_v2b_6(a, b);
}

void	sort_man3_v2b_1(t_stack **a, t_stack **b)
{
	pa(b, a);
	ra(a);
	pa(b, a);
	ra(a);
	pa(b, a);
	ra(a);
}

void	sort_man3_v2b_2(t_stack **a, t_stack **b)
{
	pa(b, a);
	pa(b, a);
	ra(a);
	ra(a);
	pa(b, a);
	ra(a);
}
