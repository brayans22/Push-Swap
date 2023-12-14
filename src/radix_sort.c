#include "../headers/push_swap.h"

int	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		status;
	int		i;
	int		j;
	int		size;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	while (!is_sorted(stack_a) && status != ERROR)
	{
		j = 0;
		while (j++ < size && status != ERROR)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				status = rotate(stack_a, RA);
			else
				status = push(stack_b, stack_a, PB);
		}
		while (ft_lstsize(*stack_b) != 0 && status != ERROR)
			status = push(stack_a, stack_b, PA);
		i++;
	}
	return (status);
}
