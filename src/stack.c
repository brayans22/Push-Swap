#include "../headers/push_swap.h"

int     create_new_stack(t_list **stack_a, int *numbers, int total)
{
    t_list	*new;
	int		i;

	i = -1;
	while (++i < total)
	{
		new = ft_lstnew(numbers[i]);
        if (!new)
        {
            write(1, ERROR_MALLOC, 19);
            return (free_stack(stack_a), ERROR);
        }
        new->index = i;
		ft_lstadd_back(stack_a, new);
	}
    return (1);
}