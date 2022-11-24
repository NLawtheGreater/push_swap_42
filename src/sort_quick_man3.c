/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_man3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:05:42 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 22:05:44 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_man3_v2b_3(t_stack **a, t_stack **b)
{
	pa(b, a);
	ra(a);
	pa(b, a);
	pa(b, a);
	ra(a);
	ra(a);
}

void	sort_man3_v2b_4(t_stack **a, t_stack **b)
{
	pa(b, a);
	pa(b, a);
	pa(b, a);
	ra(a);
	sa(a);
	ra(a);
	ra(a);
}

void	sort_man3_v2b_5(t_stack **a, t_stack **b)
{
	pa(b, a);
	pa(b, a);
	pa(b, a);
	ra(a);
	ra(a);
	ra(a);
}

void	sort_man3_v2b_6(t_stack **a, t_stack **b)
{
	pa(b, a);
	pa(b, a);
	ra(a);
	pa(b, a);
	ra(a);
	ra(a);
}
