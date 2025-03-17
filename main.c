/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 02:03:48 by rahmoham          #+#    #+#             */
/*   Updated: 2025-03-17 02:03:48 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	undo_rev(t_stack **a, t_stack **b)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		pb(b, a);
		i++;
	}
	i = 0;
	while (i < size)
	{
		rrb(b);
		pa(a, b);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	get_args(ac, av, &stack_a);
	if (rev_sorted(stack_a) && stack_size(stack_a) > 5)
		undo_rev(&stack_a, &stack_b);
	else if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) < 4)
			sort_three(&stack_a);
		else if (stack_size(stack_a) < 6)
			sort_five(&stack_a, &stack_b);
		else
			sort_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
