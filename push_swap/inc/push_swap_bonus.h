/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:27:05 by khovakim          #+#    #+#             */
/*   Updated: 2022/05/23 18:51:05 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PUSH_SWAP_BONUS_H
# define    PUSH_SWAP_BONUS_H

# include	"get_next_line.h"

typedef struct s_stack
{
	struct s_stack		*next;
	int					nbr;
	int					index;
}						t_stack;

t_stack	*ft_create_stack(int content);
t_stack	*ft_last_node_of_stack(t_stack *top);
int		ft_size_of_stack(t_stack *top);
void	ft_push_front(t_stack **stack, t_stack *top);
void	ft_push_back(t_stack **stack, t_stack *node);

void	ft_chek_arg(int ac, char **av);
void	errors(int flag);
char	**ft_split(char *s, char c);
int		ft_is_stack_sorted(t_stack *stack);
int		ft_atoi(char *str);
size_t	ft_strlcpy(char	*dst, char *src, size_t dstsize);

void	pa(t_stack **stack_b, t_stack **stack_a, int n);
void	pb(t_stack **stack_a, t_stack **stack_b, int n);
void	rra(t_stack **stack_a, int n);
void	rrb(t_stack **stack_b, int n);
void	rrr(t_stack **stack_a, t_stack **stack_b, int n);
void	ra(t_stack **stack_a, int n);
void	rb(t_stack **stack_b, int n);
void	rr(t_stack **stack_a, t_stack **stack_b, int n);
void	sa(t_stack **stack_a, int n);
void	sb(t_stack **stack_b, int n);
void	ss(t_stack **stack_a, t_stack **stack_b, int n);

void	ft_free_stack(t_stack **stack);
void	ft_free_str_arr(char **str);

#endif