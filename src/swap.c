/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:49:48 by bsaiago-          #+#    #+#             */
/*   Updated: 2024/01/08 19:52:27 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	make_swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		aux_cont;
	int		aux_index;

	head = *stack;
	if (!head && !head->next)
		return (ERROR);
	next = head->next;
	aux_cont = head->content;
	aux_index = head->index;
	head->content = next->content;
	head->index = next->index;
	next->content = aux_cont;
	next->index = aux_index;
	return (0);
}

int	swap(t_list **stack, char *message)
{
	if ((ft_lstsize(*stack) < 2) || make_swap(stack) == ERROR)
	{
		write(2, "Error\n", 6);
		return (ERROR);
	}
	if (write(1, message, 3) == ERROR)
		return (ERROR);
	return (1);
}
