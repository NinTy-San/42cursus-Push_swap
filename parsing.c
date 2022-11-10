/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:07:48 by adohou            #+#    #+#             */
/*   Updated: 2022/11/10 19:08:54 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_args(int ac, char **av)
{
	int		i;
	long	nb;
	t_list	*pile_a;
	t_list	*new;

	pile_a = NULL;
	new = NULL;
	i = 1;
	nb = 0;
	while (i < ac)
	{
		if (!is_int(av[i]))
			return (write_error(&pile_a), NULL);
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (write_error(&pile_a), NULL);
		new = ft_lstnew(nb);
		if (!new)
			return (NULL);
		ft_lstadd_back(&pile_a, new);
		i++;
	}
	if (!check_double(pile_a, ac))
		return (ft_lst_free(&pile_a), NULL);
	return (pile_a);
}

long	ft_atoi(const char *nptr)
{
	int		i;
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

	tmp = NULL;
	i = 1;
	if (!pile_a)
		return (0);
	while (i < ac)
	{
		j = i;
		tmp = pile_a;
		while (j < ac)
		{
			if (i != j && pile_a->value == tmp->value)
				return (write(2, "Error\n", 6), 0);
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
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		else if ((av[i] == '-' || av[i] == '+')
			&& (av[i + 1] >= '0' && av[i + 1] <= '9'))
			i++;
		else if ((av[i] >= '0' && av[i] <= '9')
			&& (av[i + 1] >= '0' && av[i + 1] <= '9'))
			i++;
		else if ((av[i] >= '0' && av[i] <= '9')
			&& av[i + 1] == ' ')
			i++;
		else if ((av[i] >= '0' && av[i] <= '9')
			&& av[i + 1] == '\0')
			i++;
		else
			return (0);
	}
	return (1);
}
