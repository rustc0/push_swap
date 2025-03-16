/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:37:10 by rahmoham          #+#    #+#             */
/*   Updated: 2025/03/16 07:43:55 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP

# define PUSH_SWAP

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				data;
	int				ch_start;
	int				ch_end;
}	t_stack;

//	parsing :

void	get_args(int ac, char **av, t_stack **stack);
void	free_array(char **arr);
void	free_stack(t_stack **stack);
void	free_all(t_stack **stack, char **arr);
int		syntx_check(char **av);
int		is_sorted(t_stack *stack);

// operations :

void	push(t_stack **dst, t_stack **src);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	r_rotate(t_stack **stack);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// sorting

void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack, t_stack **b);

// others

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*stack_min(t_stack *stack);
t_stack	*stack_max(t_stack *stack);
int		stack_size(t_stack	*stack);
int		*ft_convert(t_stack *a);
int		*sorted_copy(t_stack *a, int len);
int		chunk_size(int size);
int		find_max_position(t_stack **stack);
void	sort_stack(t_stack **a, t_stack **b);
void	update_i(int *ch_start, int *ch_end, int len);
void	update_i(int *ch_start, int *ch_end, int len);
int		syntax_error(char *av);

#endif