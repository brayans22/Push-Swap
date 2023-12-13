#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Includes */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* Constants */
# define STATUS_NOT_ARE_NUMBERS         -3
# define STATUS_NUMBER_OUT_OF_RANGE     -4
# define STATUS_TOO_FEW_ARGUMENTS       -6
# define STATUS_NUMBER_DUPLICATED       -7
# define ERROR                          -1
# define TRUE                           1
# define FALSE                          0  
# define MIN_COUNT_ARGC                 1
# define MIN_DIGIT_CHAR                 '0'
# define MAX_DIGIT_CHAR                 '9'
# define MAX_INT                        2147483647
# define MIN_INT                        -2147483648
# define SA                         "sa\n"
# define PA                         "pa\n"
# define PB                         "pb\n"
# define RA                         "ra\n"
# define ERROR_NOT_ARE_NUMBERS      "Error\nThe argvs have to be numbers\n"
# define ERROR_SWAPPING         "Error\nSwapping in the stack\n"
# define ERROR_PUSHING          "Error\nPushing in the stack\n"
# define ERROR_ROTATING         "Error\nRotating in the stack\n"
# define ERROR_INT_OVERFLOW     "Error\nArgv numbers out of integers range\n"
# define ERROR_TO_FEW_ARGUMENTS     "Error\nToo Few Arguments\n"
# define ERROR_DUPLICATED_NUMBER    "Error\nDuplicated Number In Argv\n"
# define ERROR_MALLOC               "Error\nMalloc fails\n"

/* Structs */
typedef struct s_list
{
    int             content;
    int             index;
    struct s_list   *next;
}   t_list;

/* Prototypes */
long    ft_atol(const char *str);
int     *get_numbers_from_argv(int argc, char **argv);
int	    is_sorted(t_list **stack);
int     create_new_stack(t_list **stack_a, int *numbers, int argc);
int	    ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int     radix_sort(t_list **stack_a, t_list **stack_b);

#endif //PUSH_SWAP_H