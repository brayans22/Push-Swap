/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:39:46 by bsaiago-          #+#    #+#             */
/*   Updated: 2024/01/08 19:41:15 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (ERROR);
	*stack_a = NULL;
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_b)
		return (free_stack(stack_a), ERROR);
	*stack_b = NULL;
	if (!is_valid_input(argv))
		return (free_stack(stack_a), free_stack(stack_b), ERROR);
	else if (create_new_stack(stack_a, argv) == ERROR)
		return (free_stack(stack_a), free_stack(stack_b), ERROR);
	else if (is_sorted(stack_a))
		return (free_stack(stack_a), free_stack(stack_b), 0);
	select_sort(stack_a, stack_b, argc - 1);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
