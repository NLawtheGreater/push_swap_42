void run(t_stack **a, t_stack **b)
{
	lst_check(a);
	while (count_stack(b) < count_stack(a))
	{
		if(count_stack(b) > 1)
		{
			if(((*b)->data < (*b)->next->data) && ((*a)->data > (*a)->next->data))
			 {
				ss(a, b);
				pb(a, b);
			 }
			else if((*b)->data < (*b)->next->data)
			 {
				sb(b);
				pb(a, b);
			 }
			else if((*a)->data > (*a)->next->data)
			{
				sa(a);
				pb(a, b);
			}
			else 
				pb(a, b);
		}
		else if((*a)->data > (*a)->next->data)
		{
			sa(a);
			pb(a, b);
		}
		else 
			pb(a, b);
	}
	run2 (a, b);
}

void	run2(t_stack **a, t_stack **b)
{
	int	a3;
	int	b3;
	t_stack *tmp;

	while (!check_algo1(a, b))
	{
		tmp = ft_lstlast(*a);
		a3 = tmp->data;
		tmp = ft_lstlast(*b);
		b3 = tmp->data;
		
		if ((*a)->data > a3 && a3 > b3 && b3 > (*b)->data)
			rrr(a, b);
		//else if ((*a)->next->data > (*a)->data && (*a)->data > (*b)->data && (*b)->data > (*b)->next->data)
		//	pb(a, b);
		else if (a3 > (*a)->data && (*a)->data > (*b)->data && (*b)->data > b3)
		{
			rrr(a, b);
			ss(a, b);
		}
		else if (a3 > b3 && b3 > (*a)->data && (*a)->data > (*b)->data)
		{
			pb(a, b);
			rrr(a, b);
		}
		else if ((*a)->data > (*b)->data && (*b)->data > a3 && a3 > b3)
		{
			pa(b, a);
			rrr(a, b);
		}
		else if (a3 > (*a)->data && (*a)->data > b3 && b3 >(*b)->data)
		{
			rrr(a, b);
			sa(a);
		}
		else if ((*a)->data > (*a)->next->data && (*a)->next->data > (*b)->next->data && (*b)->next->data > (*b)->data)
		{
			ss(a, b);
			pb(a, b);
		}	
		else if ((*a)->next->data > (*a)->data && (*a)->data > (*b)->next->data && (*b)->next->data > (*b)->data)
		{
			sb(b);
			pb(a, b);
		}
		else if ((*a)->data > (*a)->next->data && (*a)->next->data > (*b)->data && (*b)->data > (*b)->next->data)
		{
			sa(a);
			pb(a, b);
		}
		else if ((*a)->data > a3 && a3 > (*b)->data && (*b)->data > b3)
		{
			rra(a);
			pa(b, a);
			rrb(b);
		}
		else if ((*a)->data > b3 && b3 > a3 && a3 > (*b)->data)
		{
			rrb(b);
			pa(b, a);
			rra(a);
		}
		else if ((*b)->data > (*a)->data && (*a)->data > b3 && b3 > a3)
		{
			pa(b, a);
			rrr(a, b);
			pb(b, a);
			ss(a, b);
		}
		else if ((*b)->data > (*a)->data && (*a)->data > a3 && a3 > b3)
		{
			ra(a);
			pa(b, a);
			rra(a);
			rrr(a, b);
		}
		else if ((*b)->data > a3 && a3 > b3 && b3 > (*a)->data)
		{
			pb(a, b);
			sb(b);
			pa (b, a);
			rrr(a, b);
		}
		else if (b3 > a3 && a3 > (*b)->data && (*b)->data > (*a)->data)
		{
			pb(a, b);
			rrr(a, b);
			pa(b, a);
			ss(a, b);
		}
		else if ((*a)->data > (*b)->data && (*b)->data > b3 && b3 > a3)
		{
			pa(b, a);
			rrr(a, b);
			pa(b, a);
			sa(a);
		}
		else if (b3 > a3 && a3 > (*a)->data && (*a)->data > (*b)->data)
		{
			pb(a, b);
			rrr(a, b);
			pa(b, a);
			sa(a);
		}
		else if ((*b)->next->data > (*a)->next->data && (*a)->next->data > (*a)->data && (*a)->data > (*b)->data)
		{
			rr(a, b);
			pa(b, a);
			sa(a);
			rra(a);
		}
		else if ((*a)->data > b3 && b3 > (*b)->data && (*b)->data > a3)
		{
			rrb(b);
			pa(b, a);
			pa(b, a);
			rra(a);
		}
		else if ((*a)->next->data > (*b)->data && (*b)->data > (*b)->next->data && (*b)->next->data > (*a)->data)
		{
			ra(a);
			pa(b, a);
			pa(b, a);
			rra(a);
		}
		else if ((*a)->data > (*b)->data && (*b)->data > (*b)->next->data && (*b)->next->data > (*a)->next->data)
		{
			sa(a);
			ra(a);
			pa(b, a);
			pa(b, a);
			rra(a);
		}
		else if ((*b)->data > (*a)->next->data && (*a)->next->data > (*a)->data && (*a)->data > (*b)->next->data)
		{
			rb(b);
			pb(a, b);
			pb(a, b);
			rrb(b);
		}
		else if ((*a)->next->data > (*b)->next->data && (*b)->next->data > (*b)->data && (*b)->data > (*a)->data)
		{
			ra(a);
			sb(b);
			pa(b, a);
			pa(b, a);
		}
		else if (b3 > (*a)->data && (*a)->data > (*b)->data && (*b)->data > a3)
		{
			rra(a);
			pb(a, b);
			rrb(b);
			pa(b, a);
			ss(a, b);
		}
		else if (a3 > b3 && b3 > (*b)->data && (*b)->data > (*a)->data)
		{
			rb(b);
			pb(a, b);
			rra(a);
			rrb(b);
			rrb(b);
		}
		else if (b3 > (*a)->data && (*a)->data > a3 && a3 > (*b)->data)
		{
			rra(a);
			pb(a, b);
			rrb(b);
			pa(b, a);
			sa(a);
		}
		else if ((*b)->next->data > (*a)->data && (*a)->data > (*a)->next->data && (*a)->next->data > (*b)->data)
		{
			ss(a, b);
			rb(b);
			pb(a, b);
			pb(a, b);
			rrb(b);
		}
		else if ((*a)->data > (*b)->next->data && (*b)->next->data > (*b)->data &&  (*b)->data > (*a)->next->data)
		{
			ss(a, b);
			ra(a);
			pa(b, a);
			pa(b, a);
			rra(a);
		}
		else if ((*b)->data > (*a)->next->data && (*a)->next->data > (*b)->next->data && (*b)->next->data > (*a)->data)
		{
			rb(b);
			sa(a);
			pb(a, b);
			pb(a, b);
			rrb(b);
		}
		else if ((*b)->data > (*a)->data && (*a)->data > (*a)->next->data && (*a)->next->data > (*b)->next->data)
		{
			rb(b);
			sa(a);
			pb(a, b);
			pb(a, b);
			rrb(b);
		}
		else if ((*b)->data > (*a)->data && (*a)->data > (*b)->next->data && (*b)->next->data > (*a)->next->data)
		{
			sa(a);
			pb(a, b);
			sb(b);
			pa(b, a);
			ss(a, b);
		}
		else if (a3 > (*b)->data && (*b)->data > b3 && b3 > (*a)->data)
		{
			pb(a, b);
			sb(b);
			rrr(a, b);
			sb(b);
			pa(a, b);
			pa(a, b);
		}
		else if (a3 > (*b)->data && (*b)->data > (*a)->data && (*a)->data > b3)
		{
			pa(b, a);
			sa(a);
			rrb(b);
			pb(a, b);
			pb(a, b);
			rra(a);
		}
		else if (b3 > (*b)->data && (*b)->data > (*a)->data && (*a)->data > a3)
		{
			rb(b);
			rra(a);
			pb(a, b);
			pb(a, b);
			rrb(b);
			rrb(b);
		}
		else if ((*b)->data > b3 && b3 > (*a)->data && (*a)->data > a3)
		{
			ra(a);
			pa(b, a);
			rrb(b);
			pa(b, a);
			rra(a);
			rra(a);
		}
		else if (b3 > (*b)->data && (*b)->data > a3 && a3 > (*a)->data)
		{
			rb(b);
			pb(a, b);
			rra(a);
			pb(a, b);
			rrb(b);
			rrb(b);
		}
		else if ((*b)->data > (*b)->next->data && (*b)->next->data > (*a)->next->data && (*a)->next->data > (*a)->data)
		{
			ra(a);
			ra(a);
			pa(b, a);
			pa(b, a);
			rra(a);
			rra(a);
		}
		else if ((*b)->next->data > (*a)->next->data && (*a)->next->data > (*a)->data && (*a)->data > (*b)->data)
		{
			rr(a, b);
			pa(b, a);
			sa(a);
			rrb(b);
			pa(b, a);
			rra(a);
		}
		
	/*ft_printf("This is a stack:\n");
	lst_check(a);
	ft_printf("\n");
	ft_printf("This is b stack:\n");
	lst_check(b);
	ft_printf("\n");*/
	}
	algo_l(a, b);
	/*lst_check(a);
	ft_printf("a: %i b: %i\n", count_stack(a), count_stack(b));
	lst_check(b);*/
}