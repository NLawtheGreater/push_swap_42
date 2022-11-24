#include "push_swap.h"

int	find_tar_s(t_stack **stack)
{
	int	sm;
	int	sm_2;
	int	x;

	sm = alt_smallest(stack);
	sm_2 = alt_smallest2(stack);
	/*ft_printf("This is a stack:\n");
	lst_check(stack);
	ft_printf("\n");
	ft_printf("%i-%i-%i\n", sm, sm_2, sm_3);*/
	if(count_stack(stack) < 5)
		{
		sm_2 = -1;
		}
	x = 0;
	while(x < (count_stack(stack)/2 + 1))
	{
		if(1 + x == sm || 1 + x == sm_2)
			return (1 + x);
		if((count_stack(stack) - x) == sm || (count_stack(stack) - x) == sm_2)
			return (count_stack(stack) - x);
		x++;
	}
	return (0);
}

int	alt_smallest(t_stack **stack)
{
	t_stack *tmp;
	int	sm;
	int	seq;
	
	sm = extreme(stack, 's');
	tmp = *stack;
	seq = 1;
	while (tmp)
	{
		if(sm == tmp->data)
			return(seq);
		tmp = (tmp)->next;
		seq++;
	}
	return(0);
}

int	alt_smallest2(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;
	int	sm;
	int	sm2;
	int	seq;
	
	sm = extreme(stack, 's');
	sm2 = (*stack)->data;
	tmp = (*stack)->next;
	seq = 1;
	while (tmp)
	{
		if(sm2 == sm || (sm2 > tmp->data && tmp->data > sm))
		{
			sm2 = tmp->data;
			tmp2 = *stack;
			seq = 1;
			while(tmp2 != tmp)
			{
				tmp2 = tmp2->next;
				seq++;
			}
		}
		tmp = (tmp)->next;
	}
	return(seq);
}

int	extreme(t_stack **stack, char c)
{
	t_stack *tmp;
	int	ext;
	
	if(c == 's')
	{
	ext = (*stack)->data;
	tmp = (*stack)->next;
	while (tmp)
	{
		if(ext > tmp->data)
			ext = tmp->data;
		tmp = (tmp)->next;
	}
	}
	else if (c == 'l')
	{
		ext = (*stack)->data;
		tmp = (*stack)->next;
		while (tmp)
		{
			if(ext < tmp->data)
				ext = tmp->data;
			tmp = (tmp)->next;
		}
	}
	return(ext);
}