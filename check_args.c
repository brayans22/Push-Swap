#include "push_swap.h"

static int get_numbers_to_stack(int argc, char **argv)
{
    int i;
    int j;
    int

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

int is_valid_input(int argc, char **argv)
{
    if (argc <= MIN_COUNT_ARGC)
    {
        write(1, ERROR_TO_FEW_ARGUMENTS, 25);
        return (ERROR);
    }
    get_numbers_to_stack()
    

    return (TRUE);
}