#include "push_swap.h"

static int is_valid_numbers(int argc, char **argv)
{
    int     i;
    int     j;
    long    nb;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (!(argv[i][j] >= MIN_DIGIT_CHAR \
            && argv[i][j] <= MAX_DIGIT_CHAR) && (argv[i][j] != '-'))
                return (STATUS_NOT_ARE_NUMBERS);
            j++;
        }
        nb = ft_atol(argv[i]);
        if (nb < 0)
            return (STATUS_NUMBER_NEGATIVE);
        else if (nb > MAX_INT)
            return (STATUS_NUMBER_OUT_OF_RANGE);
        i++;
    }
    return (TRUE);
}

int is_valid_input(int argc, char **argv)
{
    int status;

    if (argc <= MIN_COUNT_ARGC)
    {
        write(1, ERROR_TO_FEW_ARGUMENTS, 24);
        return (ERROR);
    }
    status = is_valid_numbers(argc, argv);
    if (status == STATUS_NOT_ARE_NUMBERS)
    {
        write(1, ERROR_NOT_ARE_NUMBERS, 35);
        return (ERROR);
    }
    if (status == STATUS_NUMBER_OUT_OF_RANGE)
    {
        write(1, ERROR_INT_OVERFLOW, 41);
        return (ERROR);
    }
    if (status == STATUS_NUMBER_NEGATIVE)
    {
        write(1, ERROR_NUMBERS_NEGATIVE, 36);
        return (ERROR);
    }
    return (TRUE);
}