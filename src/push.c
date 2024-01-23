/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:38:16 by bsaiago-          #+#    #+#             */
/*   Updated: 2024/01/08 19:39:37 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	make_push(t_list **stack_dest, t_list **stack_origin)
{
	t_list	*head_dest;
	t_list	*head_origin;
	t_list	*aux;

	head_dest = *stack_dest;
	head_origin = *stack_origin;
	aux = head_origin;
	head_origin = head_origin->next;
	*stack_origin = head_origin;
	if (head_dest)
	{
		aux->next = head_dest;
		*stack_dest = aux;
	}
	else
	{
		head_dest = aux;
		head_dest->next = NULL;
		*stack_dest = head_dest;
	}
}

int	push(t_list **stack_dest, t_list **stack_origin, char *message)
{
	if (ft_lstsize(*stack_origin) == 0)
	{
		write(2, "Error\n", 6);
		return (ERROR);
	}
	make_push(stack_dest, stack_origin);
	if ((write(1, message, 3) == ERROR))
		return (ERROR);
	return (0);
}
