#include "push_swap.h"

//Path 1: absolute smallest
void va_12(t_stack **a, t_stack **b, int total)
{
	int	count;
	int	count2;
	int	seq;
	
	count = 1;
	while (count <= (total/2))
	{
		/*ft_printf("This is a stack:\n");
		lst_check(a);
		ft_printf("\n");
		ft_printf("This is b stack:\n");
		lst_check(b);
		ft_printf("\n");*/
		
		seq = find_target(a, total, count);
		count2 = 2;
		if (seq <= ((total - count + 1)/2))
		{
			while (count2 <= seq)
			{
				ra(a);
				count2++;
			}
		}
		else
		{
			count2 = 0;
			while (count2 <= (total - count + 1 - seq))
			{
				rra(a);
				count2++;
			}

		}
		pb(a, b); 
		count++;
	}
	shift3(a, b, count_stack(a));

	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	
	va_3(a, b);
	if (check_algo1(a, b))
	{
		algo_l(a, b);
		ft_lstclear(a);
		exit(0);
	}
	
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	
	return_x(a, b, total/2);
	
	if (check_algo1(a, b))
	{
		algo_l(a, b);
		ft_lstclear(a);
		exit(0);
	}
	
		/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/

	shift3_l(a, b, count_stack(b));
	if (check_algo1(a, b))
	{
		algo_l(a, b);
		ft_lstclear(a);
		exit(1);
	}
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	
	va_3_mirr(b, a);
	if (check_algo1(a, b))
	{
		algo_l(a, b);
		ft_lstclear(a);
		exit(0);
	}
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	
	return_xalt(a, b, total);
	if (check_algo1(a, b))
	{
		algo_l(a, b);
		ft_lstclear(a);
		exit(0);
	}
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/

	while (count_stack(b) > 1)
	{
		seq = find_largtar(b);
		count2 = 2;
		if (seq <= ((count_stack(b))/2))
		{
			while (count2 <= seq)
			{
				rb(b);
				count2++;
			}
		}
		else
		{
			count2 = 0;
			while (count2 <= (count_stack(b) - seq))
			{
				rrb(b);
				count2++;
			}

		}
		pa(b, a);
	}
	pa(b, a);
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
}

void	return_x(t_stack **a, t_stack **b, int bleft)
{
	int	a5;

	while(count_stack(b) > bleft)
		{
			a5 = ft_lstlast(*a)->data;
			if((*b)->data < (*a)->data && (*b)->data < a5)
			{
				pa(b, a);
			}
			else if((*b)->data > a5 && (*b)->data < (*a)->data)
			{
				pa(b, a);
				rra(a);
			}
			else if((*b)->data < (*a)->next->data && (*b)->data > (*a)->data)
			{
				ra(a);
				pa(b, a);
				rra(a);
			}
			else if((*b)->data < a5 && a5 < (*a)->data)
			{
				rra(a);
				pa(b, a);
			}
			else if((*b)->data < a5 && (*b)->data > (*a)->data)
			{
				pb(a, b);
				sb(b);
				rra(a);
				pa(b, a);
			}
			else if((*b)->data > a5 && (*b)->data > (*a)->data)
			{
				ra(a);
				pa(b, a);
				rra(a);
				rra(a);
			}
			va_3(a, b);
		}
}
void	return_xalt(t_stack **a, t_stack **b, int total)
{
	int	b5;
	int	bleft;
	if (total%2 == 1)
		bleft = total/2 + 1;
	else
		bleft = total/2;
	while(count_stack(a) > bleft)
		{
			b5 = ft_lstlast(*b)->data;
			if((*a)->data > (*b)->data && (*b)->data > b5)
			{
				pb(a, b);
			}
			else if((*a)->data < b5 && (*a)->data > (*b)->data)
			{
				pb(a, b);
				rrb(b);
			}
			else if((*a)->data > (*b)->next->data && (*a)->data < (*b)->data)
			{
				rb(b);
				pb(a, b);
				rrb(b);
			}
			else if((*a)->data > b5 && b5 > (*b)->data)
			{
				rrb(b);
				pb(a, b);
			}
			else if((*a)->data > b5 && (*a)->data < (*b)->data)
			{
				pa(b, a);
				sa(a);
				rrb(b);
				pb(a, b);
			}
			else if((*a)->data < b5 && (*a)->data < (*b)->data)
			{
				rb(b);
				pb(a, b);
				rrb(b);
				rrb(b);
			}
		}
}

void	shift3(t_stack **a, t_stack **b, int total)
{
	int	sm_a;
	int	sm_a2;
	int	a5;
	int	count;
	
	count = 1;
	sm_a2 = smallest2(a);
	while (count <= (total - 3))
	{
		a5 = ft_lstlast(*a)->data;
		sm_a = smallest(a);
	if(((*a)->data == sm_a || (*a)->data == sm_a2))
	{
		pb(a, b);
	}
	else if(a5 == sm_a || a5 == sm_a2)
	{
		rra(a);
		pb(a, b);
	}
	else if((*a)->next->data == sm_a || (*a)->next->data == sm_a2)
	{
		ra(a);
		pb(a, b);
	}
	else if((*a)->next->next->data == sm_a || (*a)->next->next->data == sm_a2)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	count++;
	}
}

void	shift3_l(t_stack **a, t_stack **b, int total)
{
	int	lg_b;
	int	lg_b2;
	int	a5;
	int	count;
	
	count = 1;
	lg_b2 = largest2(b);
	while (count <= (total - 3))
	{
		a5 = ft_lstlast(*b)->data;
		lg_b = largest(b);
	if(((*b)->data == lg_b || (*b)->data == lg_b2))
	{
		pa(b, a);
	}
	else if(a5 == lg_b || a5 == lg_b2)
	{
		rrb(b);
		pa(b, a);
	}
	else if((*a)->next->data == lg_b || (*a)->next->data == lg_b2)
	{
		rb(b);
		pa(b, a);
	}
	else if((*a)->next->next->data == lg_b || (*a)->next->next->data == lg_b2)
	{
		rb(b);
		rb(b);
		pa(b, a);
	}
	else
	{
		rrb(b);
		rrb(b);
		pa(b, a);
	}
	count++;
	}
}

int	find_target(t_stack **stack, int total, int count)
{
	int	sm;
	int	sm_2;
	int	sm_3;
	int	x;

	sm = alt_smallest(stack);
	sm_2 = alt_smallest2(stack);
	sm_3 = alt_smallest3(stack);
	/*ft_printf("This is a stack:\n");
	lst_check(stack);
	ft_printf("\n");
	ft_printf("%i-%i-%i\n", sm, sm_2, sm_3);*/
	if(count > (total/2 - 2))
		{
		sm_2 = -1;
		sm_3 = -1;
		}
	x = 0;
	while(x < ((total - count)/2 + 1))
	{
		if(1 + x == sm || 1 + x == sm_2 || 1 + x == sm_3)
			return (1 + x);
		if((total - count + 1 - x) == sm || (total - count + 1 - x) == sm_2 ||\
		 (total - count + 1 - x) == sm_3)
			return (total - count + 1 - x);
		x++;
	}
	return (0);
}
int	find_largtar(t_stack **stack)
{
	int	lg;
	/*int	lg_2;
	int	lg_3;*/
	int	x;

	lg = alt_largest(stack);
	/*lg_2 = alt_largest2(stack);
	lg_3 = alt_largest3(stack);
	if(count_stack(b) < 3)
		{
		lg_2 = -1;
		lg_3 = -1;
		}*/
	x = 0;
	while(x < (count_stack(stack)/2)+1)
	{
		if(1 + x == lg /*|| 1 + x == lg_2 || 1 + x == lg_3*/)
			return (1 + x);
		if((count_stack(stack) - x) == lg /*|| (total - count + 1 - x) == sm_2 ||\
		 (total - count + 1 - x) == lg_3*/)
			return (count_stack(stack) - x);
		x++;
	}
	return (0);
}

int	alt_largest(t_stack **stack)
{
	t_stack *tmp;
	int	lg;
	int	seq;
	
	lg = largest(stack);
	tmp = *stack;
	seq = 1;
	while (tmp)
	{
		if(lg == tmp->data)
			return(seq);
		tmp = (tmp)->next;
		seq++;
	}
	return(0);
}

int	alt_smallest(t_stack **stack)
{
	t_stack *tmp;
	int	sm;
	int	seq;
	
	sm = smallest(stack);
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
	
	sm = smallest(stack);
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

int	alt_smallest3(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;
	int	sm2;
	int sm3;
	int	seq;
	
	sm2 = smallest2(stack);
	sm3 = (*stack)->data;
	tmp = (*stack)->next;
	seq = 1;
	while (tmp)
	{
		if(sm3 <= sm2 || (sm3 > tmp->data && tmp->data > sm2))
		{
			sm3 = tmp->data;
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