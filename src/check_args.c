#include "../headers/push_swap.h"

static int  *alloc_memory_numbers(int argc)
{
    int *values_int;
    int i;

    values_int = (int *)malloc(sizeof(int) * argc);
    i = -1;
    if (!values_int)
        return (NULL);
    while (++i < argc)
        values_int[i] = -1;
    return (values_int);
}

int *get_numbers_from_argv(int argc, char **argv)
{
    int *numbers;
    
    if (argc <= 1)
        return (0);
    numbers = alloc_memory_numbers(argc - 1);
    if (!numbers)
        return (NULL);
    else if (!is_valid_input(argc, argv, numbers))
    {
        free(numbers);
        numbers = NULL;
    }
    return (numbers);
}
