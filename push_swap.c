#include "push_swap.h"

/*
static void fill_stack(t_stack **stack, int *numbers)
{
    t_stack *aux;


}
*/

int main(int argc, char **argv)
{
    //t_stack *stack_a;
    //t_stack *stack_b;
    int     *numbers;

    //stack_a = NULL;
    //stack_b = NULL;
    numbers = get_numbers_from_argv(argc, argv);
    if (!numbers)
        return (ERROR);
    /* ADD ELEMENTS TO THE STACK A */
    //fill_stack(stack_a, numbers);
    free(numbers);
    return 0;
}