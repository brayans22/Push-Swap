#include "../headers/push_swap.h"

void free_stack(t_node *stack) 
{
    t_node *current;
    t_node *next;

    current = stack;
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
}

static t_node*  create_node(int content, t_node *next, t_node *before)
{
    t_node *node;
    node = (t_node *)malloc(sizeof(t_node));
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

static int create_new_stack(t_node **stack, int *numbers, int total)
{
    int     i;
    t_node  *head;

    i = 0;
    head = create_node(numbers[i], NULL, NULL);
    if (!head)
    {
        write(1, ERROR_MALLOC, 19);
        return (ERROR);
    }
    (*stack) = head;
    while (++i < total)
    {
        head->next = create_node(numbers[i], NULL, head);
        if (!head->next)
        {
            write(1, ERROR_MALLOC, 19);
            free_stack(head);
            (*stack) = NULL;
            return (ERROR);
        }
        head = head->next;
    }
    return (TRUE);
}

int main(int argc, char **argv)
{
    t_node  *stack_a;
    //t_node  *stack_b;
    int     *numbers;

    stack_a = NULL;
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
