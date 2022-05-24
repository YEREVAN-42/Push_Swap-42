/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:00:24 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/21 15:29:31 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	if ((*stack_a)->nbr > (*stack_a)->next -> nbr
		&& (*stack_a)->nbr > ft_last_node_of_stack(*stack_a)->nbr)
	{
		ra(stack_a, 1);
		if (!ft_is_stack_sorted(*stack_a))
			sa(stack_a, 1);
	}
	else if ((*stack_a)->nbr < (*stack_a)->next -> nbr)
	{
		rra(stack_a, 1);
		if (!ft_is_stack_sorted(*stack_a))
			sa(stack_a, 1);
	}
	else
		sa(stack_a, 1);
}

static void	ft_sort_fourth(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_get_distance_of_node(*stack_a, min_nbr_of_stack(*stack_a));
	if (distance == 1)
		ra(stack_a, 1);
	else if (distance == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (distance == 3)
		rra(stack_a, 1);
	if (ft_is_stack_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	ft_sort_three(stack_a);
	pa(stack_b, stack_a, 1);
}

static void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_get_distance_of_node(*stack_a, min_nbr_of_stack(*stack_a));
	if (distance == 1)
		ra(stack_a, 1);
	else if (distance == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (distance == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (distance == 4)
		rra(stack_a, 1);
	if (ft_is_stack_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	ft_sort_fourth(stack_a, stack_b);
	pa(stack_b, stack_a, 1);
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_indexing(stack_a);
	if (ft_size_of_stack(*stack_a) == 2)
		sa(stack_a, 1);
	else if (ft_size_of_stack(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_size_of_stack(*stack_a) == 4)
		ft_sort_fourth(stack_a, stack_b);
	else if (ft_size_of_stack(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}
