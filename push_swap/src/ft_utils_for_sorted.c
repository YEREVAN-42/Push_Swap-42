






/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_for_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:20:30 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/20 14:47:53 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_stack_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node -> next)
	{
		if (node -> nbr > node -> next -> nbr)
			return (0);
		node = node -> next;
	}
	return (1);
}

int	min_nbr_of_stack(t_stack *stack)
{
	int	number;

	number = stack -> nbr;
	stack = stack -> next;
	while (stack)
	{
		if (number > stack -> nbr)
			number = stack -> nbr;
		stack = stack -> next;
	}
	return (number);
}

static t_stack	*ft_get_next_min_nbr(t_stack *stack)
{
	t_stack	*top;
	t_stack	*min;
	int		has_min;

	has_min = 0;
	min = NULL;
	top = stack;
	while (top)
	{
		if (top -> index == -1 && (has_min == 0 || top -> nbr < min -> nbr))
		{
			has_min = 1;
			min = top;
		}
		top = top ->next;
	}
	return (min);
}

void	ft_indexing(t_stack **stack)
{
	t_stack	*top;
	int		index;

	index = -1;
	top = ft_get_next_min_nbr(*stack);
	while (top)
	{
		top -> index = ++index;
		top = ft_get_next_min_nbr(*stack);
	}
}

int	ft_get_distance_of_node(t_stack *stack, int nbr)
{
	int	distance;

	distance = 0;
	while (stack)
	{
		if (nbr == stack -> nbr)
			break ;
		++distance;
		stack = stack -> next;
	}
	return (distance);
}
