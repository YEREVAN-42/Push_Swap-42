/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:33:07 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/21 18:40:38 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_stack(t_stack **stack, int ac, char **av)
{
	t_stack		*node;
	char		**inputs;
	char		*str;
	int			i;

	i = 0;
	str = "\0";
	while (++i < ac)
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
	}
	i = -1;
	inputs = ft_split(str, ' ');
	while (inputs[++i])
	{
		node = ft_create_stack(ft_atoi(inputs[i]));
		ft_push_back(stack, node);
	}
	ft_free_str_arr(inputs);
	free(str);
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac < 2)
		return (0);
	ft_chek_arg(ac, av);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	ft_fill_stack(stack_a, ac, av);
	if (ft_is_stack_sorted(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_sort_stack(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
