/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:06 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/23 18:30:35 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_true(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	ft_str_isdigit(char *str)
{
	int	i;
	int	sg;

	i = -1;
	sg = 0;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			sg++;
	}
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	else
		i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57 || sg > 1)
			return (0);
		i++;
	}
	return (1);
}

static long int	ft_atol(char *str)
{
	long int	a;
	int			n;

	a = 0;
	n = 0;
	while (is_true(*str, "\t\n\v\f\r "))
		str++;
	if (*str == '-')
	{
		n = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a *= 10;
		a += (*str - 48);
		str++;
	}
	if (n == 1)
		return (-1 * a);
	else
		return (a);
}

static int	ft_is_repeated(long int num, char **av, int i)
{
	while (av[++i])
	{
		if (num == ft_atol(av[i]))
			return (1);
	}
	return (0);
}

void	ft_chek_arg(int ac, char **av)
{
	static char		*str = "\0";
	char			**inputs;
	long int		tmp;
	int				i;

	i = 0;
	while (++i != ac)
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
	}
	inputs = ft_split(str, ' ');
	i = -1;
	while (inputs[++i])
	{
		tmp = ft_atol(inputs[i]);
		if (!ft_str_isdigit(inputs[i]) || ft_is_repeated(tmp, inputs, i)
			|| tmp < -2147483648 || tmp > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	ft_free_str_arr(inputs);
	free(str);
}
