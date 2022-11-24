/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man4a_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:31 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/24 14:31:33 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man4_a10(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if ((*a)->next->data < a3 && a3 < (*a)->data && (*a)->data < a4)
	{
		pb(a, b);
		ra(a);
		ra(a);
		pa(b, a);
		*size -= 2;
	}
	else if ((*a)->next->data < a4 && a4 < a3 && a3 < (*a)->data)
	{
		pb(a, b);
		ra(a);
		sa(a);
		ra(a);
		ra(a);
		pa(b, a);
		*size -= 3;
	}
}

void	sort_man4_a11(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if (a4 < (*a)->next->data && (*a)->next->data < a3 && a3 < (*a)->data)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		pa(b, a);
		*size -= 3;
	}
	else if ((*a)->next->data < a3 && a3 < a4 && a4 < (*a)->data)
	{
		pb(a, b);
		ra(a);
		ra(a);
		ra(a);
		pa(b, a);
		*size -= 3;
	}
}

void	sort_man4_a12(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if ((*a)->data < (*a)->next->data && (*a)->next->data < a4 && a4 < a3)
	{
		ra(a);
		ra(a);
		sa(a);
		*size -= 2;
	}
	else if ((*a)->data < a4 && a4 < (*a)->next->data && (*a)->next->data < a3)
	{
		ra(a);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		*size -= 2;
	}
}
