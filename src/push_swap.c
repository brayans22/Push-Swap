#include "../headers/push_swap.h"



static t_list*  create_node(int content, t_list *next, t_list *before)
{
    t_list *node;
    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
    {
        write(1, ERROR_MALLOC, 19);
        return (NULL);
    }
    node->content = content;
    node->before = before;
    node->next = next;
    return (node);
}

static void create_new_stack(t_list **stack, int *numbers, int total)
{
    int     i;
    t_list  *head;
    
    i = 0;
    (*stack) = NULL;
    head = create_node(numbers[i], NULL, NULL);
    if (!head)
        write(1, ERROR_MALLOC, 19);
    else
    {
        (*stack) = head;
        while (++i < total && (*stack))
        {
            head->next = create_node(numbers[i], NULL, head);
            if (!head->next)
            {
                write(1, ERROR_MALLOC, 19);
                free_stack(head);
                (*stack) = NULL;
            }
            else
                head = head->next;
        }
    }
}

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
    int     *numbers;

    //stack_b = NULL;
    numbers = get_numbers_from_argv(argc, argv);
    if (!numbers)
        return (ERROR);
    create_new_stack(&stack_a, numbers, argc - 1);
    if (!stack_a)
        return (ERROR);
    for (int i = 0; stack_a != NULL; i++)
    {
        printf("[%i]->", stack_a->content);
        stack_a = stack_a->next;
    }
    printf("\n");
    free(numbers);
    free_stack(stack_a);
    /*
    if (argc - 1 == 2)
    {
        sa_swap_a(&stack_a, argc - 1);
    }
    */
    return 0;
}
