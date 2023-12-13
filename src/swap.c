#include "../headers/push_swap.h"

void sa_swap_a(t_node **stack, int total)
{
    t_node  **head;
    t_node  *aux; 

    head = stack;
    if (!(*stack) || !stack)
        return ;
    if (total == 2 && (*stack)->content >= (*stack)->next->content)
    {
        aux = (*stack); 
        (*stack) = (*stack)->next;
        aux -> next = NULL;
        aux -> before = (*stack);
        (*stack)->next = aux;
        (*stack)->before = NULL;
    }
    else
    {
        //SI TENGO MAS DE 2;
    }
    stack = head;
}