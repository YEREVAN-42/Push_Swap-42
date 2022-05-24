/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_libft_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:42:32 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/18 16:07:56 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*str;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s2 || !result)
		return (0);
	str = result;
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (result);
}

size_t	ft_strlcpy(char	*dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (src[i] && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	char	*ptr;
	char	b;

	ptr = (char *)s;
	b = c;
	while (*ptr && *ptr != b)
		ptr++;
	if (*ptr == b)
		return (ptr);
	return (0);
}

int	ft_atoi(char *str)
{
	int	a;
	int	n;

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
