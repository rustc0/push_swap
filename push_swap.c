#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;

    stack_a = NULL;
	get_args(ac, av, &stack_a);
    t_stack *tmp = stack_a;
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    free_stack(&stack_a);
    return (0);
}
