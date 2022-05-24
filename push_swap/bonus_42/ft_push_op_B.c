/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_op_B.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:06:39 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/23 18:49:41 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

static void	ft_push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (ft_size_of_stack(*stack_src) != 0)
	{
		tmp = *stack_src;
		*stack_src = tmp -> next;
		ft_push_front(stack_dst, tmp);
	}
}

void	pa(t_stack **stack_b, t_stack **stack_a, int n)
{
	ft_push(stack_b, stack_a);
	if (n == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int n)
{
	ft_push(stack_a, stack_b);
	if (n == 1)
		write(1, "pb\n", 3);
}
