/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:43:42 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/21 15:11:45 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*node;

	if (ft_size_of_stack(*stack) > 2)
	{
		node = ft_last_node_of_stack(*stack);
		head = *stack;
		*stack = (*stack)->next;
		node -> next = head;
		head -> next = NULL;
	}
}

void	ra(t_stack **stack_a, int n)
{
	ft_rotate(stack_a);
	if (n == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int n)
{
	ft_rotate(stack_b);
	if (n == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int n)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (n == 1)
		write(1, "rr\n", 3);
}
