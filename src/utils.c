/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:34:01 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:34:03 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_tar_s(t_stack **stack)
{
	int	sm;
	int	sm_2;
	int	x;

	sm = alt_smallest(stack);
	sm_2 = alt_smallest2(stack);
	if (count_stack(stack) < 5)
		sm_2 = -1;
	x = 0;
	while (x < (count_stack(stack) / 2 + 1))
	{
		if (1 + x == sm || 1 + x == sm_2)
			return (1 + x);
		if ((count_stack(stack) - x) == sm || (count_stack(stack) - x) == sm_2)
			return (count_stack(stack) - x);
		x++;
	}
	return (0);
}

int	alt_smallest(t_stack **stack)
{
	t_stack	*tmp;
	int		sm;
	int		seq;

	sm = extreme(stack, 's');
	tmp = *stack;
	seq = 1;
	while (tmp)
	{
		if (sm == tmp->data)
			return (seq);
		tmp = (tmp)->next;
		seq++;
	}
	return (0);
}

int	alt_smallest2(t_stack **stack)
{
	t_stack	*tmp;
	int		sm;
	int		sm2;
	int		seq;

	sm = extreme(stack, 's');
	sm2 = (*stack)->data;
	tmp = (*stack)->next;
	while (tmp)
	{
		if (sm2 == sm || (sm2 > tmp->data && tmp->data > sm))
		{
			sm2 = tmp->data;
			alt_sm2_helper(stack, tmp, &seq);
		}
		tmp = (tmp)->next;
	}
	return (seq);
}

void	alt_sm2_helper(t_stack **stack, t_stack *tmp, int *ptr)
{
	t_stack	*tmp2;

	*ptr = 1;
	tmp2 = *stack;
	while (tmp2 != tmp)
	{
		tmp2 = tmp2->next;
		*ptr += 1;
	}
}

int	extreme(t_stack **stack, char c)
{
	t_stack	*tmp;
	int		ext;

	ext = (*stack)->data;
	tmp = (*stack)->next;
	if (c == 's')
	{
		while (tmp)
		{
			if (ext > tmp->data)
				ext = tmp->data;
			tmp = (tmp)->next;
		}
	}
	else if (c == 'l')
	{
		while (tmp)
		{
			if (ext < tmp->data)
				ext = tmp->data;
			tmp = (tmp)->next;
		}
	}
	return (ext);
}
