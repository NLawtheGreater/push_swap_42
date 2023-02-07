/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:19:10 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/22 16:19:23 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
 /*main functions*/
int		main_con(t_stack **a, t_stack **b);
int		check_dup(t_stack **a);
void	sort_man(t_stack **a, t_stack **b);
void	sort_man5(t_stack **a, t_stack **b);

void	sort_man5_con(t_stack **a, t_stack **b, int seq);
void	sort_man3(t_stack **a);
/*insert functions*/
void	sort_insrt(t_stack **a, t_stack	**b);
int		e1_into_stack(t_stack **a, t_stack **b, char x);
void	e1_into_stack_con(t_stack **a, t_stack **b, t_stack *tmp, int *ptr);
void	sort_insrt2(t_stack **a, t_stack	**b);
void	sort_insrt2_con(t_stack **a, t_stack **b, int seq);
void	sort_insrt2_con2(t_stack **a, t_stack **b, int seq);
int		check_stack(t_stack **stack, char x);
int		check_stack_con(t_stack *tmp);

/*quick functions*/
void	sort_quick(t_stack **a, t_stack	**b);
void	quick_a(t_stack **a, t_stack	**b, 	int size);
void	quick_b(t_stack **a, t_stack	**b, int size);
void	quick_1a(t_stack **a, t_stack	**b, int size);
int		quick_1a_con(t_stack **a, t_stack**b, int size, int *record);
void	quick_1b(t_stack **a, t_stack	**b, int size);
int		quick_1b_con(t_stack **a, t_stack**b, int size, int *record);

int		pivot_check(t_stack *stack, int pivot, int size);
int		man_check(t_stack *stack, int size);
void	find_median(t_stack *stack, int size, int *pivot);
void	find_median_con(t_stack *tmp, int size, int **pivot, int *delta);

int		sort_man4_a(t_stack **a, t_stack **b, int size);
void	sort_man4_a_con(t_stack **a, t_stack **b, int *size, int size_check);
void	sort_man4_a2(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a3(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a4(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a5(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a6(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a7(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a8(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a9(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a10(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a11(t_stack **a, t_stack **b, int *size, int a3);
void	sort_man4_a12(t_stack **a, t_stack **b, int *size, int a3);

int		sort_man4_b(t_stack **a, t_stack **b, int size);
void	sort_man4_b_con(t_stack **a, t_stack **b, int *size, int size_check);
void	sort_man4_b_con2(t_stack **a, t_stack **b, int *size, int size_check);
void	sort_man4_b2(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b3(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b4(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b5(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b6(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b7(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b8(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b9(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b10(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b11(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b12(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b13(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b14(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b15(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b16(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b17(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b18(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b19(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b20(t_stack **a, t_stack **b, int *size, int b3);
void	sort_man4_b21(t_stack **a, t_stack **b, int *size, int b3);


void	sort_man_v2a(t_stack **a, t_stack **b, int size);
void	sort_man3_v2a_1(t_stack **a, int *size);
void	sort_man3_v2a_2(t_stack **a, t_stack	**b, int *size);
void	sort_man3_v2a_3(t_stack **a, t_stack	**b, int *size);


void	sort_man3_v2a_4(t_stack **a, t_stack	**b, int *size);

int		sort_man3_v2a(t_stack **a, t_stack	**b, int size);
void	sort_man_v2b(t_stack **a, t_stack **b, int size);
void	sort_man3_v2b(t_stack **a, t_stack	**b);
void	sort_man3_v2b_1(t_stack **a, t_stack **b);
void	sort_man3_v2b_2(t_stack **a, t_stack **b);
void	sort_man3_v2b_3(t_stack **a, t_stack **b);
void	sort_man3_v2b_4(t_stack **a, t_stack **b);
void	sort_man3_v2b_5(t_stack **a, t_stack **b);
void	sort_man3_v2b_6(t_stack **a, t_stack **b);
/*utils functions*/
int		find_tar_s(t_stack **stack);
int		alt_smallest(t_stack **stack);
int		alt_smallest2(t_stack **stack);
void	alt_sm2_helper(t_stack **stack, t_stack *tmp, int *ptr);
int		extreme(t_stack **stack, char c);
/*stack work*/
int		count_stack(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
void	rrb(t_stack **b);
void	rra(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	sa(t_stack **a);
#endif
