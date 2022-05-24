/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:05:47 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/21 18:40:27 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PUSH_SWAP_H
# define    PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack		*next;
	int					nbr;
	int					index;
}						t_stack;

t_stack		*ft_create_stack(int content);
t_stack		*ft_last_node_of_stack(t_stack *top);
void		ft_push_front(t_stack **stack, t_stack *top);
void		ft_push_back(t_stack **stack, t_stack *node);
int			ft_size_of_stack(t_stack *top);

void		ft_chek_arg(int ac, char **av);
int			is_true(char c, char *str);
int			ft_atoi(char *str);
char		*ft_strchr(char *s, int c);
char		**ft_split(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char	*dst, char *src, size_t dstsize);
size_t		ft_strlen(const char *s);

void		ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void		ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void		ft_indexing(t_stack **stack);
int			ft_is_stack_sorted(t_stack *stack);
int			min_nbr_of_stack(t_stack *stack);
int			ft_get_distance_of_node(t_stack *stack, int nbr);

void		sa(t_stack **stack_a, int n);
void		sb(t_stack **stack_b, int n);
void		ss(t_stack **stack_a, t_stack **stack_b, int n);

void		pa(t_stack **stack_b, t_stack **stack_a, int n);
void		pb(t_stack **stack_a, t_stack **stack_b, int n);

void		ra(t_stack **stack_a, int n);
void		rb(t_stack **stack_b, int n);
void		rr(t_stack **stack_a, t_stack **stack_b, int n);

void		rra(t_stack **stack_a, int n);
void		rrb(t_stack **stack_b, int n);
void		rrr(t_stack **stack_a, t_stack **stack_b, int n);

void		ft_free_str_arr(char **str);
void		ft_free_stack(t_stack **stack);

#endif
