#include "../headers/push_swap.h"

void	print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("[cont: %i idx: %i] -> ", tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

static void sort_3(int first, int second, int third, t_list **stack_a)
{
    if (first > second && first > third && third > second)
        rotate(stack_a, RA);
    else if (first < second && first < third)
    {
        swap(stack_a, SA);
        rotate(stack_a, RA);
    }
    else if (first > second && first > third && second > third)
    {  
        swap(stack_a, SA);
        rotate(stack_a, RA);
        rotate(stack_a, RA);
    }
    else if (first < second && first > third)
    {
        rotate(stack_a, RA);
        rotate(stack_a, RA);
    }
    else if (third > second && third > first && first > second)
        swap(stack_a, SA);
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance_pos_min;

	distance_pos_min = get_distance_head_to_index(stack_a, get_min(stack_a, -1));
	if (distance_pos_min == 1)
		rotate(stack_a, RA);
	else if (distance_pos_min == 2)
	{
		rotate(stack_a, RA);
		rotate(stack_a, RA);
	}
	else if (distance_pos_min == 3)
        reverse_rotate(stack_a, RRA);
	push(stack_b, stack_a, PB);
	sort_3((*stack_a)->content, (*stack_a)->next->content, \
        (*stack_a)->next->next->content, stack_a);
	push(stack_a, stack_b, PA);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance_pos_min;

	distance_pos_min = get_distance_head_to_index(stack_a, get_min(stack_a, ERROR));
	if (distance_pos_min == 1)
		rotate(stack_a, RA);
	else if (distance_pos_min == 2)
	{
		rotate(stack_a, RA);
		rotate(stack_a, RA);
	}
	else if (distance_pos_min == 3)
	{
        reverse_rotate(stack_a, RRA);
        reverse_rotate(stack_a, RRA);
	}
	else if (distance_pos_min == 4)
		reverse_rotate(stack_a, RRA);
	push(stack_b, stack_a, PB);
	sort_4(stack_a, stack_b);
	push(stack_a, stack_b, PA);
}

static void basic_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2 && !is_sorted(stack_a))
		swap(stack_a, SA);
    else if (size == 3)
        sort_3((*stack_a)->content, (*stack_a)->next->content, \
        (*stack_a)->next->next->content, stack_a);
    else if (size == 4)
        sort_4(stack_a, stack_b);
    else if (size == 5)
        sort_5(stack_a, stack_b);
}

int select_sort(t_list **stack_a, t_list **stack_b, int size)
{
    print_list(*stack_a);
    if (size >= 2 && size <= 5)
        basic_sort(stack_a, stack_b, size);
    else    
        radix_sort(stack_a, stack_b);
    print_list(*stack_a);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
