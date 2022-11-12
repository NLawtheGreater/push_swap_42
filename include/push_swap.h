
#ifndef	PUSH_SWAP_H 
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	return3(t_stack **a, t_stack **b, int bleft);
int	alt_smallest3(t_stack **stack);
int	alt_smallest2(t_stack **stack);
int	alt_smallest(t_stack **stack);
int	find_target(t_stack **stack, int total, int count);
void	shift3(t_stack **a, t_stack **b, int total);
void	shift3_l(t_stack **a, t_stack **b, int total);
void va_12(t_stack **a, t_stack **b, int total);
int	check_algol(t_stack **a, t_stack **b, int bleft);
void	va_6(t_stack **a, t_stack **b, int total);
int	smallest(t_stack **stack);
int	smallest2(t_stack **stack);
int	largest(t_stack **stack);
int	largest2(t_stack **stack);
void	va_3(t_stack **a, t_stack **b);
void	lst_check(t_stack **lst);
void run(t_stack **a, t_stack **b);
void	run2(t_stack **a, t_stack **b);
int	check_algo1(t_stack **a, t_stack **b);
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
void	algo_l(t_stack **a, t_stack **b);
#endif