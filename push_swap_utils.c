/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:39:55 by adohou            #+#    #+#             */
/*   Updated: 2022/10/01 21:20:46 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	int	i;
	long	nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}


int	check_int_args(int ac, int *args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!args)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (j < ac)
		{
			if(i != j && args[i] == args[j])
				return (0);
		j++;
		}
		i++;
	}
	return (1);
}
int	is_int(char *av)
{
	int		i;

	i = 0;
	while(av[i])
	{
		if (av[i] == ' ' || av[i] == '-' || (av[i] >= '0' && av[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	*get_args(int ac, char **av, int *args)
{
	int		i;
	long	nb;


	if (!args)
		return (NULL);
	i = 1;
	nb  = 0;

	while (i < ac)
	{
		if (!is_int(av[i]))
			return (NULL);
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return NULL;
		args[i - 1] = nb;
		i++;
	}
	if (!check_int_args(ac, args))
		return (0);
	return (args);
}