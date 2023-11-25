#include "push_swap.h"

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

static int  is_duplicated_nb(int *values, int count, long nb)
{
    int i;

    i = -1;
    while (++i < count)
    {
        if (values[i] == (int)nb)
            return (TRUE);
    }
    return (FALSE);
}

static int  is_valid_numbers(int argc, char **argv, int *values)
{
    int     i;
    int     j;
    long    nb;

    if (argc <= MIN_COUNT_ARGC)
        return (STATUS_TOO_FEW_ARGUMENTS);
    i = 0;
    while (++i < argc)
    {
        j = -1;
        while (argv[i][++j])
        {
            if (((!(argv[i][j] >= '0' && argv[i][j] <= '9')) && \
                ((j != 0) || (j == 0 && (argv[i][j] != '-')))))
                return (STATUS_NOT_ARE_NUMBERS);
        }
        nb = ft_atol(argv[i]);
        if (nb < MIN_INT || nb > MAX_INT)
            return (STATUS_NUMBER_OUT_OF_RANGE);
        else if (is_duplicated_nb(values, i, nb))
            return (STATUS_NUMBER_DUPLICATED);
        values[i] = nb;
    }
    return (TRUE);
}

static int is_valid_input(int argc, char **argv, int *numbers)
{
    int status;

    status = is_valid_numbers(argc, argv, numbers);
    if (status == TRUE)
        return (status);
    else if (status == STATUS_NOT_ARE_NUMBERS)
        write(1, ERROR_NOT_ARE_NUMBERS, 35);
    else if (status == STATUS_NUMBER_OUT_OF_RANGE)
        write(1, ERROR_INT_OVERFLOW, 41);
    else if (status == STATUS_NUMBER_DUPLICATED)
        write(1, ERROR_DUPLICATED_NUMBER, 32);
    else
        write(1, ERROR_TO_FEW_ARGUMENTS, 24);
    return (FALSE);
}

int *get_numbers_from_argv(int argc, char **argv)
{
    int *numbers;

    numbers = alloc_memory_numbers(argc);
    if (!numbers)
        write(1, ERROR_MALLOC, 19);
    else if (!is_valid_input(argc, argv, numbers))
    {
        free(numbers);
        numbers = NULL;
    }
    return (numbers);
}
