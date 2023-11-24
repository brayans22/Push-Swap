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
int     is_valid_input(int argc, char **argv);
long    ft_atol(const char *str);


#endif //PUSH_SWAP_H