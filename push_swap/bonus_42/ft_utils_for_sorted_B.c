/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_for_sorted_B.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:20:30 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/23 18:50:00 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

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
