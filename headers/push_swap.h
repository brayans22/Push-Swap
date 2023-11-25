#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Includes */
# include "constants.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* Structs */
typedef struct s_node
{
    int             content;
    struct s_node   *next;
    struct s_node   *before;
}   t_node;

/* Prototypes */
long    ft_atol(const char *str);
int     *get_numbers_from_argv(int argc, char **argv);

#endif //PUSH_SWAP_H