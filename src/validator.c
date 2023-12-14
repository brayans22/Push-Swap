#include "../headers/push_swap.h"

static int is_a_number(char **argv, int i, int j) {
    if (j == 0) 
    {
        if ((argv[i][j] == '-' && argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9') \
        || (argv[i][j] >= '0' && argv[i][j] <= '9'))
            return (1);
    }
    else if (j > 0)
        return (argv[i][j] >= '0' && argv[i][j] <= '9');
    return (0);
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

    i = 0;
    while (++i < argc)
    {
        j = -1;
        while (argv[i][++j])
        {
            if (!is_a_number(argv, i, j))
                return (STATUS_NOT_ARE_NUMBERS);
        }
        nb = ft_atol(argv[i]);
        if (nb < MIN_INT || nb > MAX_INT)
            return (STATUS_NUMBER_OUT_OF_RANGE);
        else if (is_duplicated_nb(values, i, nb))
            return (STATUS_NUMBER_DUPLICATED);
        values[i - 1] = nb;
    }
    return (TRUE);
}

int is_valid_input(int argc, char **argv, int *numbers)
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
    return (FALSE);
}
