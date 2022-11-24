/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man4b_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:08:38 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/24 16:08:41 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man4_b9(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if (b4 < b3 && b3 < (*b)->data && (*b)->data < (*b)->next->data)
	{
		pa(b, a);
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		sa(a);
		ra(a);
		ra(a);
		*size -= 4;
	}
}

void	sort_man4_b10(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if (b3 < (*b)->next->data && (*b)->next->data < b4 && b4 < (*b)->data)
	{
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		*size -= 4;
	}
}

void	sort_man4_b11(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if (b4 < b3 && b3 < (*b)->next->data && (*b)->next->data < (*b)->data)
	{
		pa(b, a);
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		ra(a);
		*size -= 4;
	}
	else if ((*b)->next->data < b3 && b3 < (*b)->data && (*b)->data < b4)
	{
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		*size -= 3;
	}
}

void	sort_man4_b12(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if ((*b)->next->data < b4 && b4 < b3 && b3 < (*b)->data)
	{
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		*size -= 4;
	}
}

void	sort_man4_b13(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if ((*b)->next->data < b3 && b3 < b4 && b4 < (*b)->data)
	{
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		*size -= 4;
	}
}
