


static int  basic_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
    int status;

	size = swap(stack_a, SA);
	if (size == 2)
		status = swap(stack_a, SA);
	else if (size == 3)
		//sort_3(stack_a);
	else if (size == 4)
		//sort_4(stack_a, stack_b);
	else if (size == 5)
		//sort_5(stack_a, stack_b);
    return (status);
}

int select_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int status;

    if (size >= 2 && size <= 5)
        status = basic_sort(stack_a, stack_b)
    else
        status = radix_sort(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (status);
}