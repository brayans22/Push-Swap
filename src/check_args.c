/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:35:55 by bsaiago-          #+#    #+#             */
/*   Updated: 2024/01/23 12:15:12 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <string.h>

static int	ft_atoi(const char *str)
{
	int		sign;
	int		nb;

	sign = 1;
	nb = 0;
	while (*str == '\t' || *str == '\v' || *str == '\f' || \
		*str == '\n' || *str == ' ' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= MIN_DIGIT_CHAR && *str <= MAX_DIGIT_CHAR)
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}

static int	is_alpha_num(char *nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (0);
	if (nb[0] == '-' && (nb[1] >= '0' && nb[1] <= '9'))
		i++;
	while (nb[i])
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

static int	is_repeat_nb(int nb, char **argv, int pos)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return (0);
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) == nb && i != pos)
			return (1);
	}
	return (0);
}

static int	is_valid_number(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		i++;
	while (nb[i])
	{
		if (nb[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_input(char **argv)
{
	int		i;
	int		is_v;
	long	tmp;

	if (!*argv || !argv)
		return (0);
	i = 0;
	is_v = 1;
	while (argv[++i] && is_v)
	{
		tmp = ft_atol(argv[i]);
		if (!is_valid_number(argv[i]))
			is_v = 0;
		if (!is_alpha_num(argv[i]))
			is_v = 0;
		if (is_repeat_nb(ft_atoi(argv[i]), argv, i))
			is_v = 0;
		if (tmp < MIN_INT || tmp > MAX_INT \
				|| (ft_strlen_nb(argv[i]) > 10 && argv[i][0] != '-') \
			|| (ft_strlen_nb(argv[i]) > 11 && argv[i][0] == '-'))
			is_v = 0;
	}
	if (!is_v)
		write(2, "Error\n", 6);
	return (is_v);
}
