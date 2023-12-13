#include "../headers/push_swap.h"

int	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		status;
	int		j;
	int		size;

	i = 0;
	status = 0;
	size = ft_lstsize(stack_a);
	while (!is_sorted(stack_a) && status != ERROR)
	{
		j = 0;
		while (j++ < size && status != ERROR)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				status = ra(stack_a);
			else
				status = pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0 && status != ERROR)
			status = pa(stack_a, stack_b);
		i++;
	}
	return (status);
}
