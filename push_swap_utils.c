/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:39:55 by adohou            #+#    #+#             */
/*   Updated: 2022/10/03 21:56:50 by adohou           ###   ########.fr       */
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


int	check_double(t_list *pile_a, int ac)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = 1;
	if (!pile_a)
		return (0);
	while (i < ac)
	{
		j = i;
		tmp = pile_a;
		while (j < ac)
		{
			if(i != j && pile_a->value == tmp->value)
				return (0);
		tmp = tmp->next;
		j++;
		}
		pile_a = pile_a->next;
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

t_list *get_args(t_list *pile_a, int ac, char **av)
{
	int		i;
	long	nb;
	t_list	*new;
	// t_list	*start;

	i = 1;
	nb  = 0;
	while (i < ac)
	{
		if (!is_int(av[i]))
			return (NULL);
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (NULL);
		new = ft_lstnew(nb);
		if (!new)
			return (NULL);
		ft_lstadd_back(&pile_a, new);
		i++;
	}
	if (!check_double(pile_a, ac))
		return (NULL);
	return (pile_a);
}