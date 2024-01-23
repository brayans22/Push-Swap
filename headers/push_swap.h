/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:00:27 by bsaiago-          #+#    #+#             */
/*   Updated: 2024/01/23 12:02:49 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Includes */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* Constants */
# define STATUS_NOT_ARE_NUMBERS         -3
# define STATUS_NUMBER_OUT_OF_RANGE     -4
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
# define RRA                        "rra\n"

/* Structs */
typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

/* Prototypes */
long	ft_atol(const char *str);
int		is_sorted(t_list **stack);
int		create_new_stack(t_list **stack_a, char **argv);
int		ft_lstsize(t_list *lst);
int		radix_sort(t_list **stack_a, t_list **stack_b);
int		swap(t_list **stack, char *message);
int		push(t_list **stack_dest, t_list **stack_origin, char *message);
int		rotate(t_list **stack, char *message);
int		select_sort(t_list **stack_a, t_list **stack_b, int size);
int		get_distance_head_to_index(t_list **stack, int index);
int		reverse_rotate(t_list **stack, char *message);
int		is_valid_input(char **argv);
int		get_min(t_list **stack, int content);
int		ft_strlen_nb(char *str);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_stack(t_list **stack);

#endif //PUSH_SWAP_H
