/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 06:10:18 by rahmoham          #+#    #+#             */
/*   Updated: 2025/03/06 00:35:12 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (!*src)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (!*dst)
	{
		*dst = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dst;
		(*dst)->prev = node;
		*dst = node;
	}
}

void	swap(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*node;

	if (!*stack || !(*stack)->next)
		return ;
	node = ft_stacklast(*stack);
	node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	node->next->prev = node;
	node->next->next = NULL;
}
void	r_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next) 
		return ;
	last = ft_stacklast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
