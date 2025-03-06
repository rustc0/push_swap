/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:37:10 by rahmoham          #+#    #+#             */
/*   Updated: 2025/03/05 20:41:35 by rahmoham         ###   ########.fr       */
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
	int				index;
}	t_stack;

void	get_args(int ac, char **av, t_stack **stack);
void	free_array(char **arr);
void	free_stack(t_stack **stack);
void	free_all(t_stack **stack, char **arr);
int		syntx_check(char **av);
t_stack	*ft_stacklast(t_stack *stack);

// operations :

void	push(t_stack **dst, t_stack **src);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);

#endif