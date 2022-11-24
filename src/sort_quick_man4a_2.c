/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man4a_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:26 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/24 14:31:28 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man4_a5(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if (a4 < (*a)->data && (*a)->data < a3 && a3 < (*a)->next->data)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		sa(a);
		pa(b, a);
		*size -= 1;
	}
	else if ((*a)->data < a3 && a3 < a4 && a4 < (*a)->next->data)
	{
		ra(a);
		sa(a);
		ra(a);
		sa(a);
		*size -= 2;
	}
}

void	sort_man4_a6(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if (a3 < (*a)->data && (*a)->data < (*a)->next->data && \
	(*a)->next->data < a4)
	{
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		*size -= 1;
	}
	else if (a4 < a3 && a3 < (*a)->next->data && (*a)->next->data < \
	(*a)->data)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		ra(a);
		pa(b, a);
		ra(a);
		pa(b, a);
		*size -= 3;
	}
}

void	sort_man4_a7(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if (a3 < a4 && a4 < (*a)->data && (*a)->data < (*a)->next->data)
	{
		pb(a, b);
		pb(a, b);
		ra(a);
		ra(a);
		pa(b, a);
		pa(b, a);
		*size -= 2;
	}
	else if (a4 < a3 && a3 < (*a)->data && (*a)->data < (*a)->next->data)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		ra(a);
		pa(b, a);
		pa(b, a);
		*size -= 2;
	}
}

void	sort_man4_a8(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if (a3 < (*a)->next->data && (*a)->next->data < (*a)->data && \
	(*a)->data < a4)
	{
		pb(a, b);
		sa(a);
		ra(a);
		ra(a);
		pa(b, a);
		*size -= 2;
	}
	else if (a3 < (*a)->next->data && (*a)->next->data < a4 && a4 < (*a)->data)
	{
		pb(a, b);
		sa(a);
		ra(a);
		ra(a);
		ra(a);
		pa(b, a);
		*size -= 3;
	}
}

void	sort_man4_a9(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if (a3 < a4 && a4 < (*a)->next->data && (*a)->next->data < (*a)->data)
	{
		pb(a, b);
		pb(a, b);
		ra(a);
		ra(a);
		pa(b, a);
		ra(a);
		pa(b, a);
		*size -= 3;
	}
	else if (a3 < (*a)->data && (*a)->data < a4 && a4 < (*a)->next->data)
	{
		pb(a, b);
		sa(a);
		ra(a);
		sa(a);
		pa(b, a);
		*size -= 1;
	}
}
