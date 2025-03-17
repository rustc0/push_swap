/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 06:35:34 by rahmoham          #+#    #+#             */
/*   Updated: 2025/03/17 04:36:51 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_convert(t_stack *a)
{
	int	*arr;
	int	i;
	int	len;

	if (!a)
		return (NULL);
	i = 0;
	len = stack_size(a);
	arr = malloc(sizeof(int) * (stack_size(a)));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	return (arr);
}

int	*sorted_copy(t_stack *a, int len)
{
	int	*arr;

	int (i), (j), (tmp);
	arr = ft_convert(a);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	chunk_size(int size)
{
	if (!size)
		return (0);
	if (size <= 6)
		return (3);
	else if (size <= 16)
		return (4);
	else if (size <= 100)
		return (15);
	else if (size <= 500)
		return (30);
	else
		return (45);
}

int	find_max_position(t_stack **stack)
{
	t_stack	*temp;

	int (max), (max_pos), (current_pos);
	temp = *stack;
	max = temp->data;
	max_pos = 0;
	current_pos = 0;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	return (max_pos);
}

void	determine_rotation(t_stack **a, int ch_end)
{
	int	pos;
	int	size;
	
	pos = find_chunk_elem(*a, ch_end);
	size = stack_size(*a);
	if (pos <= size / 2)
		ra(a);
	else
		rra(a);
}