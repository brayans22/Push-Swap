#include "../headers/push_swap.h"

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

static int	sort_4(t_list **stack_a, t_list **stack_b)
{
    /*I have to implement this sort */
    swap(stack_a, SA);
    swap(stack_b, SA);
    return (0);
}

static int	sort_5(t_list **stack_a, t_list **stack_b)
{
    /*I have to implement this sort */
    swap(stack_a, SA);
    swap(stack_b, SA);
    return (0);
}

void	print_list(t_list *head);

static int  basic_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int status;
    //print_list(*stack_a);
	if (size == 2 && !is_sorted(stack_a))
		status = swap(stack_a, SA);
    else if (size == 3)
        status = sort_3(stack_a);
    else if (size == 4)
        status = sort_4(stack_a, stack_b);
    else if (size == 5)
        status = sort_5(stack_a, stack_b);
    //print_list(*stack_a);
    return (status);
}

void	print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("[%i ", tmp->content);
		printf(" * %i], ", tmp->index);
		tmp = tmp->next;
	}
}

int select_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int status;

    print_list(*stack_a);
    if (size >= 2 && size <= 5)
        status = basic_sort(stack_a, stack_b, size);
    else    
        status = radix_sort(stack_a, stack_b);
    print_list(*stack_a);
    free_stack(stack_a);
    free_stack(stack_b);
    return (status);
}
