#include "../headers/push_swap.h"

static void make_rotate(t_list **stack)
{
    t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int rotate(t_list **stack, char *message)
{
    if (ft_lstsize(*stack) < 2)
    {
        write(1, ERROR_ROTATING, 28);
        return (ERROR);
    }
    make_rotate(stack);
    if (write(1, message, 3) == ERROR)
        return (ERROR);
    return (0);
}
