/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_act1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:33:35 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:33:37 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (count_stack(a) > 1)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		ft_lstadd_front(a, tmp);
	}
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (count_stack(b) > 1)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		ft_lstadd_front(b, tmp);
	}
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (count_stack(a) > 1)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		ft_lstadd_front(a, tmp);
	}
	if (count_stack(b) > 1)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		ft_lstadd_front(b, tmp);
	}
	ft_printf("ss\n");
}

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = ft_lstnew((*b)->data);
		ft_lstadd_front(a, tmp);
		ft_lstdelfront(b);
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = ft_lstnew((*a)->data);
		ft_lstadd_front(b, tmp);
		ft_lstdelfront(a);
	}
	ft_printf("pb\n");
}
