/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:31:28 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/21 15:07:22 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bytes_of_index(int max_index)
{
	int	max_byts;

	max_byts = 0;
	while ((max_index >> max_byts) != 0)
		++max_byts;
	return (max_byts);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	j;

	i = -1;
	size = ft_size_of_stack(*stack_a);
	while (++i < max_bytes_of_index(size - 1))
	{
		j = -1;
		while (++j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b, 1);
		}
		while (ft_size_of_stack(*stack_b) != 0)
			pa(stack_b, stack_a, 1);
	}
}
