/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:39:55 by adohou            #+#    #+#             */
/*   Updated: 2022/10/21 19:13:11 by adohou           ###   ########.fr       */
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


void	write_error(t_list **pile_a)
{
		ft_lst_free(pile_a);
		write(2, "Error\n", 6);
}

t_list *get_args(int ac, char **av)
{
	int		i;
	long	nb;
	t_list 	*pile_a;
	t_list	*new;

	pile_a = NULL;
	new = NULL;
	i = 1;
	nb  = 0;
	while (i < ac)
	{
		if (!is_int(av[i]))
			return (write_error(&pile_a), NULL);
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (write_error(&pile_a),NULL);
		new = ft_lstnew(nb);
		if (!new)
			return (NULL);
		ft_lstadd_back(&pile_a, new);
		i++;
	}
	if (!check_double(pile_a, ac))
		return (write_error(&pile_a), NULL);
	return (pile_a);
}

void	get_index(t_list **pile_a)
{
	t_list	*start;
	t_list	*tmp;

	start = (*pile_a);
	while ((*pile_a))
	{
	tmp = start;
		while (tmp)
		{
			if (tmp->value < (*pile_a)->value)
				(*pile_a)->index += 1;
			tmp = tmp->next;
		}
		(*pile_a) = (*pile_a)->next;
	}
		(*pile_a) = start;
}
void	reset_index(t_list **pile_a)
{
	t_list	*start;

	start = (*pile_a);
	while ((*pile_a))
	{
		(*pile_a)->index = 1;
		(*pile_a) = (*pile_a)->next;
	}
		(*pile_a) = start;
}

void	get_pos(t_list **pile_a)
{
	t_list	*start;
	int		p;

	p = 1;
	start = (*pile_a);
	while((*pile_a))
	{
		(*pile_a)->pos = p++;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start;

}
// int		calc_cost(int idx, int pos, int pos_total)
// {
// 	int		cost;
// 	int		cost2;
// 	int		n;
// 	int		n2;

// 	n = 0;
// 	n2 = 0;
// 	cost = idx - pos;
// 	if ((pos_total - pos + idx) < pos_total)
// 		cost2 = pos_total - pos + idx;
// 	else
// 		cost2 = idx - (pos_total + pos );
// 	if (cost < 0)
// 	{
// 		cost *= -1;
// 		n = 1;
// 	}
// 	if (cost2 < 0)
// 	{
// 		cost2 *= -1;
// 		n2 = 1;
// 	}
// 	if(cost2 <= cost)
// 	{
// 		if(n2)
// 			cost2 /= -1;
// 		return(cost2);
// 	}
// 	if(n)
// 		cost /= -1;
// 	return(cost);
// }

void	get_best_cost(t_list **pile)
{
	t_list	*start;
	int		pos_total;

	start = (*pile);
	pos_total = ft_lstlast((*pile))->pos;
	while((*pile))
	{
		if ((*pile)->pos <= pos_total / 2 + 1)
			(*pile)->cost = (*pile)->pos - 1;
		else
			(*pile)->cost = (pos_total - (*pile)->pos + 1);
		(*pile) = (*pile)->next;
	}
	(*pile) = start;
}

void 	push_n_swap(t_list **pile_a, t_list **pile_b)
{
		pb(pile_a, pile_b);
		rb(pile_b);
}

void	pre_sort(t_list **pile_a, t_list **pile_b)
{
	int		size;
	int		half;
	int		quarter;
	int		nb_push;

	size = ft_lstsize((*pile_a));
	half = size / 2;
	printf("half = %d \n", half);
	quarter = half / 2;
	printf("quarter = %d \n", quarter);
	nb_push = 0;
	while((*pile_a))
	{
		if(nb_push == size / 2)
		{
			quarter += half;
			half = size;
		}
		if ((*pile_a)->index <= quarter)
		{
			pb(pile_a, pile_b);
			nb_push++;
		}
		else if ((*pile_a)->index <= half)
		{
			push_n_swap(pile_a, pile_b);
			nb_push++;
		}
		else
			ra(pile_a);
	}

}