#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Includes */
# include "constants.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* Structs */
typedef struct s_stack
{
    void    *content;
    struct s_stack  *next;
    struct s_stack  *before;
}   t_stack;

/* Prototypes */
long    ft_atol(const char *str);
int     *get_numbers_from_argv(int argc, char **argv);

#endif //PUSH_SWAP_H