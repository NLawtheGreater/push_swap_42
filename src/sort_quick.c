/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:33:01 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:33:03 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_quick(t_stack **a, t_stack	**b)
{
	quick_a(a, b, count_stack(a));
}

void	quick_a(t_stack **a, t_stack	**b, int size)
{
	int	pivot;
	int	record;
	int	next;

	pivot = 0;
	find_median(*a, size, &pivot);
	record = 0;
	while (pivot_check(*a, pivot, size - record))
	{
		if ((*a)->data <= pivot)
		{
			pb(a, b);
			record++;
		}
		else
			ra(a);
	}
	next = size - record;
	quick_b(a, b, record);
	quick_1a(a, b, next);
}

void	quick_b(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	record;
	int	next;

	if (size < 5 || (size == 5 && man_check(*b, 5)))
	{
		sort_man_v2b(a, b, size);
		return ;
	}
	pivot = 0;
	find_median(*b, size, &pivot);
	record = 0;
	while (pivot_check(*b, pivot, size - record))
	{
		if ((*b)->data <= pivot)
		{
			pa(b, a);
			record++ ;
		}
		else
			rb(b);
	}
	next = size - record;
	quick_1a(a, b, record);
	quick_1b(a, b, next);
}

void	quick_1a(t_stack **a, t_stack	**b, int size)
{
	int	record;
	int	next;

	if (size < 5 || (size == 5 && man_check(*a, 5)))
	{
		sort_man_v2a(a, b, size);
		return ;
	}
	record = 0;
	next = quick_1a_con(a, b, size, &record);
	while (next > 0)
	{
		rra(a);
		next--;
	}
	next = size - record;
	quick_1b(a, b, record);
	quick_1a(a, b, next);
}

int	quick_1a_con(t_stack **a, t_stack **b, int size, int *record)
{
	int	pivot;
	int	next;

	pivot = 0;
	find_median(*a, size, &pivot);
	next = 0;
	while (pivot_check(*a, pivot, size - *record - next))
	{
		if ((*a)->data <= pivot)
		{
			pb(a, b);
			*record += 1;
		}
		else
		{
			ra(a);
			next++;
		}
	}
	return (next);
}
