
#ifndef	PUSH_SWAP_H 
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	return_x(t_stack **a, t_stack **b, int bleft);
void	return_xalt(t_stack **a, t_stack **b, int bleft);
int	alt_largest(t_stack **stack);
int	alt_smallest3(t_stack **stack);
int	alt_smallest2(t_stack **stack);
int	alt_smallest(t_stack **stack);
int	find_largtar(t_stack **stack);
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
void va_3_mirr(t_stack **a, t_stack	**b);
void	lst_check(t_stack **lst);
void run(t_stack **a, t_stack **b);
void	run2(t_stack **a, t_stack **b);
int	check_algo1(t_stack **a, t_stack **b);

void	algo_l(t_stack **a, t_stack **b);
#endif