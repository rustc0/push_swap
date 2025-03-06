#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
	get_args(ac, av, &stack_a);
    rotate(&stack_a);
    // push(&stack_b, &stack_a);
    // push(&stack_b, &stack_a);
    t_stack *tmp = stack_a;
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
