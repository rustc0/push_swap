/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:52:43 by rahmoham          #+#    #+#             */
/*   Updated: 2025/03/16 05:50:39 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack *max;

	if (!stack || !*stack)
		return ;
	max = stack_max(*stack);
	if (max == *stack)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if (!is_sorted(*stack))
		sa(stack);
}

void	sort_five(t_stack **stack, t_stack **b)
{
	t_stack	*min;
	
	if (!stack || !*stack)
		return ;
	while (stack_size(*stack) > 3)
	{
		min = stack_min(*stack);
		while (min != *stack && ((*stack)->next == min))
			ra(stack);
		while (min != *stack)
			rra(stack);
		pb(b, stack);
	}
	sort_three(stack);
	pa(stack, b);
	pa(stack, b);
}

void	push_to_b(t_stack **a, t_stack **b, int *arr, int *ch_start, int *ch_end)
{
	int	len;

	len = stack_size(*a);
	while (*a)
	{
		if ((*a)->data <= arr[*ch_start])
		{
			pb(b, a);
			update_i(ch_start, ch_end, len);
			if (stack_size(*b) >= 2)
				rb(b);
		}
		else if ((*a)->data <= arr[*ch_end])
		{
			pb(b, a);
			update_i(ch_start, ch_end, len);
			if((*b)->next && (*b)->data <= (*b)->next->data)
				sb(b);
		}
		else
			ra(a);
	}
}

void	push_back(t_stack **a, t_stack **b)
{
	int	(max_pos), (size), (i);
	while (*b)
	{
		max_pos = find_max_position(b);
		size = stack_size(*b);
		if (max_pos <= size / 2)
		{
			i = 0;
			while (i < max_pos)
				(rb(b), i++);
		}
		else
		{
			i = 0;
			while (i < size - max_pos)
				(rrb(b), i++);
		}
		pa(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	*arr;

	int	(ch_start), (ch_end);
	arr = sorted_copy(*a, stack_size(*a));
	ch_start = 0;
	ch_end = chunk_size(stack_size(*a));
	push_to_b(a, b, arr, &ch_start, &ch_end);
	push_back(a, b);
	free (arr);
}
