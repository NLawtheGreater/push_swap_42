/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man4b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:08:22 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/24 16:08:24 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_man4_b(t_stack **a, t_stack **b, int size)
{
	int	b3;
	int	b4;
	int	size_check;

	size_check = size;
	b3 = (*b)->next->next->data;
	b4 = (*b)->next->next->next->data;
	if ((*b)->data < (*b)->next->data && (*b)->next->data < b3 && b3 < b4)
	{
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		size -= 3;
	}
	if (size_check == size)
		sort_man4_b2(a, b, &size, b3);
	if (size_check == size)
		sort_man4_b_con(a, b, &size, size_check);
	if (size_check == size)
		sort_man4_b_con2(a, b, &size, size_check);
	return (size);
}

void	sort_man4_b_con(t_stack **a, t_stack **b, int *size, int size_check)
{
	int	b3;

	b3 = (*b)->next->next->data;
	sort_man4_b3(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b4(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b5(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b6(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b7(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b8(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b9(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b10(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b11(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b12(a, b, size, b3);
}

void	sort_man4_b_con2(t_stack **a, t_stack **b, int *size, int size_check)
{
	int	b3;

	b3 = (*b)->next->next->data;
	if (size_check == *size)
		sort_man4_b13(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b14(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b15(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b16(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b17(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b18(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b18(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b19(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b20(a, b, size, b3);
	if (size_check == *size)
		sort_man4_b21(a, b, size, b3);
}

void	sort_man4_b2(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if ((*b)->data < (*b)->next->data && (*b)->next->data < b4 && b4 < b3)
	{
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		*size -= 4;
	}
}

void	sort_man4_b3(t_stack **a, t_stack **b, int *size, int b3)
{
	int	b4;

	b4 = (*b)->next->next->next->data;
	if (b4 < (*b)->data && (*b)->data < (*b)->next->data && (*b)->next->data \
	< b3)
	{
		pa(b, a);
		pa(b, a);
		sa(a);
		sb(b);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		*size -= 3;
	}
}
