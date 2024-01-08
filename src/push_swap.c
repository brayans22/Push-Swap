#include "../headers/push_swap.h"

int main(int argc, char **argv)
{
    t_list  **stack_a;
    t_list  **stack_b;
    int     *numbers;
    
    stack_a = (t_list **)malloc(sizeof(t_list));
    if (!stack_a)
        return (ERROR);
    *stack_a = NULL;
    stack_b = (t_list **)malloc(sizeof(t_list));
    if (!stack_b)
        return (free_stack(stack_a), ERROR);
    *stack_b = NULL;
    numbers = get_numbers_from_argv(argc, argv);
    if (!numbers)
        return (free_stack(stack_a), free_stack(stack_b), free(numbers), ERROR);
    else if (create_new_stack(stack_a, numbers, argc - 1) == ERROR)
        return (free_stack(stack_a), free_stack(stack_b), free(numbers), ERROR);
    else if (is_sorted(stack_a))
        return (free_stack(stack_a), free_stack(stack_b), free(numbers), 0);
    free(numbers);
    select_sort(stack_a, stack_b, argc - 1);
}
