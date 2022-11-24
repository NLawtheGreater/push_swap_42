/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:55:51 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/23 11:55:52 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_median_con(t_stack *tmp, int size, int **pivot, int *delta)
{
	int	j;

	j = 1;
	while (j <= size)
	{
		if (**pivot < tmp->data)
			*delta += 1;
		else if (**pivot > tmp->data)
			*delta -= 1;
		tmp = tmp->next;
		j++;
	}
}
