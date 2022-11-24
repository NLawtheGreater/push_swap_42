#include "push_swap.h"

void	sort_insrt(t_stack **a, t_stack	**b)
{
	int	count;
	int	seq;

	while(count_stack(a) > 3)
	{
		if ((*a)->next->data < (*a)->data)
			sa(a);
		seq = e1_into_stack(a, b, 'a');
		count = 1;
			while (count < seq)
			{
				rb(b);
				count++;
			}
			pb(a, b);
			while (count > 1)
			{
				rrb(b);
				count--;
			}	
		
	}
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	sort_insrt2(a, b);
}

int	e1_into_stack(t_stack **a, t_stack **b, char x)
{
	t_stack *tmp;
	int	seq;
	
	seq = 1;
	if (x == 'a')
	{
		tmp = *b;
		while (tmp)
		{
			if(count_stack(b) == 1)
				break;
			//check order of instructions
			if( (*a)->data > tmp->data)
				break;
			tmp = (tmp)->next;
			seq++;
		}
	}
	else if (x == 'b')
	{
		tmp = *a;
		while (tmp)
		{
			if(count_stack(a) == 1)
				break;
			//check order of instructions
			if((*b)->data < tmp->data)
				break;
			tmp = (tmp)->next;
			seq++;
		}
	}
	return(seq);
}

void	sort_insrt2(t_stack **a, t_stack	**b)
{
	int	count;
	int	seq;

	sort_man3(a);
	while(count_stack(b) > 0)
	{
		seq = e1_into_stack(a, b, 'b');
		count = 1;
		if (seq <= (count_stack(a)/2))
		{
			while (count < seq)
			{
				ra(a);
				count++;
			}
			pa(b, a);
			while (count > 1)
			{
				rra(a);
				count--;
			}	
		}
		else
		{
			count = -1;
			while (count < (count_stack(a) - seq))
			{
				rra(a);
				count++;
			}
			pa(b, a);
			while (count > -2)
			{
				ra(a);
				count--;
			}
		}
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	}
}

int	check_stack(t_stack **stack, char x)
{
	t_stack	*tmp;

	if (count_stack(stack) == 0)
		return (1);
	tmp = *stack;
	if (x == 'b')
	{
		while (tmp->next)
		{
			if (tmp->data > tmp->next->data)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	else if (x == 'a')
	{
		while (tmp->next)
		{
			if (tmp->data < tmp->next->data)
				tmp = tmp->next;
			else
				return (0);
		}	
	}
	return (1);
}