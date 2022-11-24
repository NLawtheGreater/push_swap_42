/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man4b_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:08:51 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/24 16:08:52 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man4_b19(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if (b3 < b4 && b4 < (*b)->data && (*b)->data < (*b)->next->data)
	{
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		sa(a);
		ra(a);
		ra(a);
		*size -= 4;
	}
}

void	sort_man4_b20(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if (b3 < b4 && b4 < (*b)->next->data && (*b)->next->data < (*b)->data)
	{
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		*size -= 4;
	}
}

void	sort_man4_b21(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if (b3 < (*b)->next->data && (*b)->next->data < (*b)->data && \
	(*b)->data < b4)
	{
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		*size -= 3;
	}
}
