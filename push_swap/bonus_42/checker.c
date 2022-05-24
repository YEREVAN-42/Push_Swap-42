/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:51:28 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/23 18:51:32 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

static void	compare(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(b, a, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
}

static void	gnl(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		compare(line, a, b);
		line = get_next_line(0);
	}
	if (!ft_is_stack_sorted(*a) || *b != NULL)
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
}

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
	if (av[1][0] == '\0')
		errors(0);
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
	gnl(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
