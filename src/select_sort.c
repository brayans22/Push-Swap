#include "../headers/push_swap.h"

static int  basic_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int status;

	if (size == 2)
		status = swap(stack_a, SA);
    else if (size == 3)
        status = swap(stack_b, SA);
    return (status);
}

int select_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int status;

    if (size >= 2 && size <= 5)
        status = basic_sort(stack_a, stack_b, size);
    else
        status = radix_sort(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (status);
}