#ifndef	PUSH_SWAP_H 
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

//main functions
int	check_dup(t_stack **a)

//stack work
int	count_stack(t_stack **stack);
void rrr(t_stack **a, t_stack **b);
void rrb(t_stack **b);
void rra(t_stack **a);
void rr(t_stack **a, t_stack **b);
void rb(t_stack **b);
void ra(t_stack **a);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **b, t_stack **a);
void ss(t_stack **a, t_stack **b);
void sb(t_stack **b);
void sa(t_stack **a);
#endif