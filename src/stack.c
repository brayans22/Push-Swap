#include "../headers/push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == ERROR) && (!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

static void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

int     create_new_stack(t_list **stack_a, int *numbers, int total)
{
    t_list	*new;
	int		content;
	int		i;

	i = -1;
	while (++i < total)
	{
		content = numbers[i];
		new = ft_lstnew(content);
		new->index = ERROR;
	        if (!new)
            		return (free_stack(stack_a), free(numbers), ERROR);
		ft_lstadd_back(stack_a, new);
	}
	index_stack(stack_a);
    return (1);
}
