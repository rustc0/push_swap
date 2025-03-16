#include "push_swap.h"

void	printstacks(t_stack *a, t_stack *b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = a;
	tmp_b = b;
	printf("stack a : ");
	while (tmp_a)
	{
		printf("%d ", tmp_a->data);
		tmp_a = tmp_a->next;
	}
	printf("\nstack b : ");
	while (tmp_b)
	{
		printf("%d ", tmp_b->data);
		tmp_b = tmp_b->next;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	get_args(ac, av, &stack_a);
	if (!is_sorted(stack_a))
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
