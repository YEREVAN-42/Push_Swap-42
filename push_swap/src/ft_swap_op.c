/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:26:38 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/21 15:10:36 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	int	swap;

	if (ft_size_of_stack(*stack) > 2)
	{
		swap = (*stack)->nbr;
		(*stack)->nbr = (*stack)->next->nbr;
		(*stack)->next->nbr = swap;
	}
}

void	sa(t_stack **stack_a, int n)
{
	ft_swap(stack_a);
	if (n == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int n)
{
	ft_swap(stack_b);
	if (n == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int n)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (n == 1)
		write(1, "ss\n", 3);
}
