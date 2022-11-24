/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man4a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:19 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/24 14:31:21 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_man4_a(t_stack **a, t_stack **b, int size)
{
	int	a3;
	int	a4;
	int	size_check;

	size_check = size;
	a3 = (*a)->next->next->data;
	a4 = (*a)->next->next->next->data;
	if ((*a)->data < (*a)->next->data && (*a)->next->data < a3 && a3 < a4)
		return (size);
	else if ((*a)->next->data < (*a)->data && (*a)->data < a3 && a3 < a4)
	{
		sa(a);
		ra(a);
		size -= 1;
	}
	if (size_check == size)
		sort_man4_a2(a, b, &size, a3);
	if (size_check == size)
		sort_man4_a3(a, b, &size, a3);
	if (size_check == size)
		sort_man4_a_con(a, b, &size, size_check);
	return (size);
}

//check if size value passes back to sort_man4_a
void	sort_man4_a_con(t_stack **a, t_stack **b, int *size, int size_check)
{
	int	a3;

	a3 = (*a)->next->next->data;
	sort_man4_a6(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a7(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a8(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a9(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a10(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a11(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a12(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a4(a, b, size, a3);
	if (size_check == *size)
		sort_man4_a5(a, b, size, a3);
}

void	sort_man4_a2(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if (a4 < (*a)->data && (*a)->data < (*a)->next->data && \
	(*a)->next->data < a3)
	{
		pb(a, b);
		pb(a, b);
		pb(a, b);
		ra(a);
		pa(b, a);
		pa(b, a);
		pa(b, a);
		*size -= 1;
	}
	else if ((*a)->next->data < (*a)->data && (*a)->data < a4 && a4 < a3)
	{
		sa(a);
		ra(a);
		ra(a);
		sa(a);
		*size -= 2;
	}
}

void	sort_man4_a3(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if ((*a)->next->data < a4 && a4 < (*a)->data && (*a)->data < a3)
	{
		pb(a, b);
		ra(a);
		sa(a);
		ra(a);
		pa(b, a);
		*size -= 2;
	}
	else if (a4 < (*a)->next->data && (*a)->next->data < (*a)->data \
	&& (*a)->data < a3)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		ra(a);
		pa(b, a);
		*size -= 2;
	}
}

void	sort_man4_a4(t_stack **a, t_stack **b, int *size, int a3)
{
	int	a4;

	a4 = (*a)->next->next->next->data;
	if ((*a)->data < a3 && a3 < (*a)->next->data && (*a)->next->data < a4)
	{
		ra(a);
		sa(a);
		*size -= 1;
	}
	else if ((*a)->data < a4 && a4 < a3 && a3 < (*a)->next->data)
	{
		ra(a);
		pb(a, b);
		sa(a);
		ra(a);
		ra(a);
		pa(b, a);
		*size -= 3;
	}
}
