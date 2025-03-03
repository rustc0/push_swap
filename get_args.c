/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_avs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:32:54 by rahmoham          #+#    #+#             */
/*   Updated: 2025/03/03 03:52:25 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(int num, t_stack *stack)
{
	t_stack	*tmp = stack;

	while (tmp)
	{
		if (tmp->data == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	append_to_stack(t_stack **stack, int data)
{
	t_stack	*new_node;
	t_stack	*temp;

	if (!stack)
		return ;
	new_node  = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		{
			free_stack(stack);
			exit (1);
		}
	new_node->data = data;
	new_node->next = NULL;
	if (!(*stack))
	{
		new_node->prev = NULL;
		*stack = new_node;
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	get_args(int ac, char **av, t_stack **stack)
{
	char	**arr;
	int	(i), (j), (num);
	if (!syntx_check(av))
		(write(2, "Error", 5), exit(1));
	i = 1;
	while (i < ac)
	{
		arr = ft_split(av[i]);
		if (!arr)
			(write(2, "Error", 5), exit(1));
		j = 0;
		while(arr[j])
		{
			if (!is_dup(ft_atol(arr[j]), *stack)
			|| (ft_atol(arr[j]) > INT_MAX || ft_atol(arr[j]) < INT_MIN))
				free_all(stack, arr);
			num = ft_atol(arr[j]);
			append_to_stack(stack, num);
			free(arr[j]);
			j++;
		}
		free (arr);
		i++;
	}
}
int syntx_check(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				j++;
				if (!(av[i][j] >= '0' && av[i][j] <= '9'))
					return (0);
				continue ;
			}
			if (!(av[i][j] >= '0' && av[i][j] <= '9') && av[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (1);
}