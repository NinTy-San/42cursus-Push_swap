/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:39:55 by adohou            #+#    #+#             */
/*   Updated: 2022/10/13 05:28:54 by adohou           ###   ########.fr       */
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

void	get_pos(t_list **pile_a)
{
	t_list  *start;
	int		p;

	p = 0;
	start = (*pile_a);
	while((*pile_a))
	{
		(*pile_a)->pos = p++;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start;

}

// void	get_index(t_list **pile_a, int idx)
// {
// 	t_list	*start;
// 	t_list	*tmp;
// 	t_list	*lower;

// 	start = (*pile_a);
// 	lower = NULL;
// 	while ((*pile_a)->next)
// 	{
// 	tmp = (*pile_a);
// 		while (tmp)
// 		{

// 			if (tmp->value < (*pile_a)->value && tmp->index < 0)
// 			{
// 				if (!lower)
// 					lower = tmp;
// 				else if(tmp->value < lower->value )
// 					lower = tmp;
// 			}
// 			if(tmp->next) ;
// 				tmp = tmp->next;

// 		}
// 		(*pile_a) = (*pile_a)->next;
// 	}
// 		(*pile_a) = start;

// 	if (lower)
// 	{
// 		while ((*pile_a)->next)
// 		{
// 			if ((*pile_a)->value == lower->value)
// 			{
// 				(*pile_a)->index = idx;
// 				idx++;
// 				break;
// 			}

// 			(*pile_a) = (*pile_// void	get_index(t_list **pile_a, int idx)
// {
// 	t_list	*start;
// 	t_list	*tmp;
// 	t_list	*lower;

// 	start = (*pile_a);
// 	lower = NULL;
// 	while ((*pile_a)->next)
// 	{
// 	tmp = (*pile_a);
// 		while (tmp)
// 		{

// 			if (tmp->value < (*pile_a)->value && tmp->index < 0)
// 			{
// 				if (!lower)
// 					lower = tmp;
// 				else if(tmp->value < lower->value )
// 					lower = tmp;
// 			}
// 			if(tmp->next) ;
// 				tmp = tmp->next;

// 		}
// 		(*pile_a) = (*pile_a)->next;
// 	}
// 		(*pile_a) = start;

// 	if (lower)
// 	{
// 		while ((*pile_a)->next)
// 		{
// 			if ((*pile_a)->value == lower->value)
// 			{
// 				(*pile_a)->index = idx;
// 				idx++;
// 				break;
// 			}

// 			(*pile_a) = (*pile_a)->next;
// 		}
// 		if ((*pile_a)->value == lower->value)
// 			{
// 				(*pile_a) = start;
// 				get_index(pile_a, idx);
// 			}
// 		(*pile_a) = start;
// 	}
// }a)->next;
// 		}
// 		if ((*pile_a)->value == lower->value)
// 			{
// 				(*pile_a) = start;
// 				get_index(pile_a, idx);
// 			}
// 		(*pile_a) = start;
// 	}
// }