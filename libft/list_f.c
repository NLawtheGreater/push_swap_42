/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:48:54 by niclaw            #+#    #+#             */
/*   Updated: 2023/02/07 19:48:57 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	lst_check(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		ft_printf("%i\n", tmp->data);
		tmp = tmp->next;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;

	if (!*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free (*lst);
		*lst = ptr;
	}
	*lst = NULL;
}

void	ft_lstdelfront(t_stack **lst)
{
	t_stack	*ptr;

	ptr = (*lst)->next;
	free(*lst);
	*lst = ptr;
}
