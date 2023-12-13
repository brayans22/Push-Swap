#include "../headers/push_swap.h"



int	sa(t_list **stack_a)
{
	if (make_swap(stack_a) == ERROR)
    {
        write(1, ERROR_SWAPPING, 28);
        return (ERROR);
    }
	write(1, SA, 3);
	return (0);
}