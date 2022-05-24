/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:38:27 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/18 19:25:19 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(int content)
{
	t_stack	*top;

	top = (t_stack *)malloc(sizeof(t_stack));
	if (!top)
		return (NULL);
	top -> nbr = content;
	top -> index = -1;
	top -> next = NULL;
	return (top);
}

t_stack	*ft_last_node_of_stack(t_stack *top)
{
	if (!top)
		return (NULL);
	while (top -> next)
		top = top -> next;
	return (top);
}

int	ft_size_of_stack(t_stack *top)
{
	int	size;

	size = 0;
	while (top)
	{
		top = top -> next;
		size++;
	}
	return (size);
}

void	ft_push_front(t_stack **stack, t_stack *top)
{
	if (!top)
		return ;
	top -> next = *stack;
	*stack = top;
}

void	ft_push_back(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!node)
		return ;
	if (*stack)
	{
		tmp = ft_last_node_of_stack(*stack);
		tmp -> next = node;
	}
	else
		*stack = node;
}
