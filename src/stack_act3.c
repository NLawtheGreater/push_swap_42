/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_act3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:33:48 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:33:50 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (count_stack(a) > 1)
	{
		tmp = ft_lstlast(*a);
		tmp2 = *a;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		ft_lstadd_front(a, tmp);
	}
	if (count_stack(b) > 1)
	{
		tmp = ft_lstlast(*b);
		tmp2 = *b;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		ft_lstadd_front(b, tmp);
	}
	ft_printf("rrr\n");
}

int	count_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		count;

	if (!*stack)
		return (0);
	tmp = *stack;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
