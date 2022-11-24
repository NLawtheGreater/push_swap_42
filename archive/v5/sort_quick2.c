#include "push_swap.h"

int	pivot_check(t_stack *stack, int pivot, int size)
{
	while (size > 0)
	{
		if(stack->data <= pivot)
			return (1);
		stack = stack->next;
		size--;
	}
	return (0);
}

int	man_check(t_stack *stack, int size)
{
	if (size == 4)
	{
		if ((stack)->next->next->next->data > (stack)->data  &&\
	 (stack)->next->next->next->data > (stack)->next->data && (stack)->next->next->next->data > (stack)->next->next->data)
	 	return (1);
	}
	 else if (size == 5)
	 {
		if ((stack)->next->next->next->next->data > (stack)->data  && (stack)->next->next->next->next->data >\
		 (stack)->next->data && (stack)->next->next->next->next->data > (stack)->next->next->data &&\
		 (stack)->next->next->next->next->data > (stack)->next->next->next->data)
	 		return (1);
	 }
	 return (0);

}

int find_median(t_stack *stack, int size)
{
	int	i;
	int	j;
	int pivot;
	int	delta;
	t_stack	*tmp;
	t_stack	*tmp2;
	
	i = 1;
	tmp2 = stack;
	while(i <= size)
	{
		pivot = tmp2->data;
		j = 1;
		tmp = stack;
		delta = 0;
		while (j <= size)
		{
			if (pivot < tmp->data)
				delta--;
			else if (pivot > tmp->data)
				delta++;
			tmp = tmp->next;
			j++;
		}
		if (delta == 0 || delta == 1 || delta == -1)
			return (pivot);
		
		tmp2 = tmp2->next;
		i++;
	}
	return (pivot);
}

int	sort_man4_a(t_stack **a, t_stack **b, int size)
{
	int	a3;
	int	a4;

	a3 = (*a)->next->next->data;
	a4 = (*a)->next->next->next->data;
	if ((*a)->data < (*a)->next->data  && (*a)->next->data < a3 && a3 < a4)
			return (size);
	else if ((*a)->data < (*a)->next->data  && (*a)->next->data < a4 && a4 < a3)
	{
		ra(a);
		ra(a);
		sa(a);
		size -= 2;
	}
	else if ((*a)->data < a4 && a4 < (*a)->next->data  && (*a)->next->data < a3)
	{
		ra(a);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		size -= 2;
	}
	else if (a4 < (*a)->data && (*a)->data < (*a)->next->data  && (*a)->next->data < a3)
	{
		pb(a, b);
		pb(a, b);
		pb(a, b);
		ra(a);
		pa(b, a);
		pa(b, a);
		pa(b, a);
		size -= 1;
	}
	else if ((*a)->next->data < (*a)->data  && (*a)->data < a3 && a3 < a4) 
		sa(a);
	else if ((*a)->next->data < (*a)->data  && (*a)->data < a4 && a4 < a3)
	{
		sa(a);
		ra(a);
		ra(a);
		sa(a);
		size -= 2;
	}
	else if ((*a)->next->data < a4  && a4 < (*a)->data && (*a)->data < a3)
	{
		pb(a, b);
		ra(a);
		sa(a);
		ra(a);
		pa(b, a);
		size -= 2;
	}
	else if (a4 < (*a)->next->data && (*a)->next->data < (*a)->data && (*a)->data < a3)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		ra(a);
		pa(b, a);
		size -= 2;
	}
	else if ((*a)->data < a3 && a3 < (*a)->next->data && (*a)->next->data < a4)
	{
		ra(a);
		sa(a);
		size -= 1;
		//
	}
	else if ((*a)->data < a4 && a4 < a3 && a3 < (*a)->next->data)
	{
		ra(a);
		pb(a, b);
		sa(a);
		ra(a);
		ra(a);
		pa(b, a);
		size -= 3;
	}
	else if (a4 < (*a)->data && (*a)->data < a3 && a3 < (*a)->next->data)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		sa(a);
		pa(b, a);
		size -= 1;
	}
	else if ((*a)->data < a3 && a3 < a4 && a4 < (*a)->next->data)
	{
		ra(a);
		sa(a);
		ra(a);
		sa(a);
		size -= 2;
		//
	}
	else if (a3 < (*a)->data && (*a)->data < (*a)->next->data && (*a)->next->data < a4)
		{
			pb(a, b);
			sa(a);
			ra(a);
			pa(b, a);
			size -= 1;
		}
	else if (a3 < (*a)->data && (*a)->data < a4 && a4 < (*a)->next->data)
	{
			pb(a, b);
			sa(a);
			ra(a);
			sa(a);
			pa(b, a);
			size -= 1;
	}
	else if (a3 < a4  && a4 < (*a)->data && (*a)->data < (*a)->next->data)
	{
			pb(a, b);
			pb(a, b);
			ra(a);
			ra(a);
			pa(b, a);
			pa(b, a);
			size -= 2;
	}
	else if (a4 < a3  && a3 < (*a)->data && (*a)->data < (*a)->next->data)
	{
			pb(a, b);
			pb(a, b);
			sa(a);
			ra(a);
			ra(a);
			pa(b, a);
			pa(b, a);
			size -= 2;
	}
	else if (a3 < (*a)->next->data && (*a)->next->data < (*a)->data && (*a)->data < a4)
	{
			pb(a, b);
			sa(a);
			ra(a);
			ra(a);
			pa(b, a);
			size -= 2;
	}
	else if (a3 < (*a)->next->data && (*a)->next->data < a4 && a4 < (*a)->data)
	{
			pb(a, b);
			sa(a);
			ra(a);
			ra(a);
			ra(a);
			pa(b, a);
			size -= 3;
	}
	else if (a3 < a4  && a4 < (*a)->next->data && (*a)->next->data < (*a)->data )
	{
			pb(a, b);
			pb(a, b);
			ra(a);
			ra(a);
			pa(b, a);
			ra(a);
			pa(b, a);
			size -= 3;
	}
	else if (a4 < a3  && a3 < (*a)->next->data && (*a)->next->data < (*a)->data )
	{
			pb(a, b);
			pb(a, b);
			sa(a);
			ra(a);
			ra(a);
			pa(b, a);
			ra(a);
			pa(b, a);
			size -= 3;
	}
	else if ((*a)->next->data < a3 && a3 < (*a)->data && (*a)->data < a4)
		{
			pb(a, b);
			ra(a);
			ra(a);
			pa(b, a);
			size -= 2;
		}
	else if ((*a)->next->data < a4  && a4 < a3  && a3 < (*a)->data)
	{
		pb(a, b);
		ra(a);
		sa(a);
		ra(a);
		ra(a);
		pa(b, a);
		size -= 3;
	}
	else if (a4 < (*a)->next->data && (*a)->next->data < a3  && a3 < (*a)->data)
	{
		pb(a, b);
		pb(a, b);
		sa(a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		pa(b, a);
		size -= 3;
	}
	else if ((*a)->next->data < a3 && a3 < a4 && a4 < (*a)->data)
		{
			pb(a, b);
			ra(a);
			ra(a);
			ra(a);
			pa(b, a);
			size -= 3;
		}
	return (size);
}

int	sort_man4_b(t_stack **a, t_stack **b, int size)
{
	int	b3;
	int	b4;

	b3 = (*b)->next->next->data;
	b4 = (*b)->next->next->next->data;
	if ((*b)->data < (*b)->next->data  && (*b)->next->data < b3 && b3 < b4)
		{
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			size -= 3;
		}
	else if ((*b)->data < (*b)->next->data  && (*b)->next->data < b4 && b4 < b3)
	{
		pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 4;
	}
	else if ((*b)->data < b4 && b4 < (*b)->next->data  && (*b)->next->data < b3)
	{
		pa(b, a);
		ra(a);
		pa(b, a);
		sb(b);
		pa(b, a);
		ra(a);
		ra(a);
		size -= 3;
	}
	else if (b4 < (*b)->data && (*b)->data < (*b)->next->data  && (*b)->next->data < b3)
	{
		pa(b, a);
		pa(b, a);
		sa(a);
		sb(b);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		size -= 3;
	}
	else if ((*b)->next->data < (*b)->data  && (*b)->data < b3 && b3 < b4)
		{
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 2;
		}
	else if ((*b)->next->data < (*b)->data  && (*b)->data < b4 && b4 < b3)
	{
		pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
		pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 4;
	}
	else if ((*b)->next->data < b4  && b4 < (*b)->data && (*b)->data < b3)
	{
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		sa(a);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		size -= 4;
	}
	else if (b4 < (*b)->next->data && (*b)->next->data < (*b)->data && (*b)->data < b3)
	{
		pa(b, a);
		pa(b, a);
		sb(b);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		size -= 3;
	}
	else if ((*b)->data < b3 && b3 < (*b)->next->data && (*b)->next->data < b4)
	{
		pa(b, a);
		ra(a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		size -= 3;
	}
	else if ((*b)->data < b4 && b4 < b3 && b3 < (*b)->next->data)
	{
		pa(b, a);
		ra(a);
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		size -= 4;
	}
	else if (b4 < (*b)->data && (*b)->data < b3 && b3 < (*b)->next->data)
	{
		pa(b, a);
		pa(b, a);
		sb(b);
		pa(b, a);
		ra(a);
		sa(a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		size -= 4;
	}
	else if ((*b)->data < b3 && b3 < b4 && b4 < (*b)->next->data)
	{
		pa(b, a);
		ra(a);
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		ra(a);
		ra(a);
		size -= 4;
	}
	else if (b3 < (*b)->data && (*b)->data < (*b)->next->data && (*b)->next->data < b4)
		{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			sa(a);
			ra(a);
			ra(a);
			size -= 3;
		}
	else if (b3 < (*b)->data && (*b)->data < b4 && b4 < (*b)->next->data)
		{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			sa(a);
			ra(a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 4;
		}
	else if (b3 < b4  && b4 < (*b)->data && (*b)->data < (*b)->next->data)
	{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			sa(a);
			ra(a);
			ra(a);
			size -= 4;
	}
	else if (b4 < b3  && b3 < (*b)->data && (*b)->data < (*b)->next->data)
	{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			sa(a);
			ra(a);
			ra(a);
			size -= 4;
	}
	else if (b3 < (*b)->next->data && (*b)->next->data < (*b)->data && (*b)->data < b4)
	{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			ra(a);
			size -= 3;
	}
	else if (b3 < (*b)->next->data && (*b)->next->data < b4 && b4 < (*b)->data)
	{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 4;
	}
	else if (b3 < b4  && b4 < (*b)->next->data && (*b)->next->data < (*b)->data )
	{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			ra(a);
			ra(a);
			size -= 4;
	}
	else if (b4 < b3  && b3 < (*b)->next->data && (*b)->next->data < (*b)->data )
	{
			pa(b, a);
			pa(b, a);
			pa(b, a);
			pa(b, a);
			ra(a);
			ra(a);
			ra(a);
			ra(a);
			size -= 4;
	}
	else if ((*b)->next->data < b3 && b3 < (*b)->data && (*b)->data < b4)
		{
			pa(b, a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 3;
		}
	else if ((*b)->next->data < b4  && b4 < b3  && b3 < (*b)->data)
	{
		pa(b, a);
		pa(b, a);
		ra(a);
		pa(b, a);
		pa(b, a);
		ra(a);
		ra(a);
		ra(a);
		size -= 4;
	}
	else if (b4 < (*b)->next->data && (*b)->next->data < b3  && b3 < (*b)->data)
	{
		pa(b, a);
		pa(b, a);
		pa(b, a);
		pa(b, a);
		ra(a);
		sa(a);
		ra(a);
		ra(a);
		ra(a);
		size -= 4;
	}
	else if ((*b)->next->data < b3 && b3 < b4 && b4 < (*b)->data)
		{
			pa(b, a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			pa(b, a);
			ra(a);
			ra(a);
			size -= 4;
		}
	return (size);
}