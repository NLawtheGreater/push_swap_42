/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:33:10 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:33:12 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_1b(t_stack **a, t_stack	**b, int size)
{
	int	record;
	int	next;

	if (size < 5 || (size == 5 && man_check(*b, 5)))
	{
		sort_man_v2b(a, b, size);
		return ;
	}
	record = 0;
	next = quick_1b_con(a, b, size, &record);
	while (next > 0)
	{
		rrb(b);
		next--;
	}
	next = size - record;
	quick_1a(a, b, record);
	quick_1b(a, b, next);
}

int	quick_1b_con(t_stack **a, t_stack**b, int size, int *record)
{
	int	pivot;
	int	next;

	pivot = 0;
	find_median(*b, size, &pivot);
	next = 0;
	while (pivot_check(*b, pivot, size - *record - next))
	{
		if ((*b)->data <= pivot)
		{
			pa(b, a);
			*record += 1;
		}
		else
		{
			rb(b);
			next++;
		}
	}
	return (next);
}

int	pivot_check(t_stack *stack, int pivot, int size)
{
	while (size > 0)
	{
		if (stack->data <= pivot)
			return (1);
		stack = stack->next;
		size--;
	}
	return (0);
}

int	man_check(t_stack *stack, int size)
{
	if (size == 4)
	{
		if ((stack)->next->next->next->data > (stack)->data && \
			(stack)->next->next->next->data > (stack)->next->data && \
			(stack)->next->next->next->data > (stack)->next->next->data)
			return (1);
	}
	else if (size == 5)
	{
		if ((stack)->next->next->next->next->data > (stack)->data && \
			(stack)->next->next->next->next->data > (stack)->next->data && \
			(stack)->next->next->next->next->data > (stack)->next->next->data \
			&& (stack)->next->next->next->next->data > \
			(stack)->next->next->next->data)
			return (1);
	}
	return (0);
}

void	find_median(t_stack *stack, int size, int *pivot)
{
	int		i;
	int		delta;
	t_stack	*tmp;
	t_stack	*tmp2;

	i = 1;
	tmp2 = stack;
	while (i <= size)
	{
		*pivot = tmp2->data;
		tmp = stack;
		delta = 0;
		find_median_con(tmp, size, &pivot, &delta);
		if (delta == 0 || delta == 1 || delta == -1)
			break ;
		tmp2 = tmp2->next;
		i++;
	}
}
