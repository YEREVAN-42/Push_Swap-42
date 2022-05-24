/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:58:16 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/21 15:12:31 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*head;

	if (ft_size_of_stack(*stack) > 2)
	{
		node = *stack;
		while (node -> next -> next)
			node = node -> next;
		head = node -> next;
		node -> next = NULL;
		head -> next = *stack;
		*stack = head;
	}
}

void	rra(t_stack **stack_a, int n)
{
	ft_reverse_rotate(stack_a);
	if (n == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int n)
{
	ft_reverse_rotate(stack_b);
	if (n == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int n)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (n == 1)
		write(1, "rrr\n", 4);
}
