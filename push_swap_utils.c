/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:39:55 by adohou            #+#    #+#             */
/*   Updated: 2022/10/24 19:40:50 by adohou           ###   ########.fr       */
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
void	get_best_cost(t_list **pile)
{
	t_list	*start;
	int		pos_total;

	start = (*pile);
	pos_total = ft_lstlast((*pile))->pos;
	while((*pile))
	{
		if ((*pile)->pos <= (pos_total / 2) + 1)
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

void	set_big_up(t_list **pile_b)
{
	t_list	*tmp;
	int		len;
	int		mouvs;

	tmp = (*pile_b);
	len = ft_lstsize((*pile_b));
	while (tmp)
	{
		if(tmp->id_sort == len)
			break ;
		tmp = tmp->next;
	}
	mouvs = tmp->cost;
	printf("bigest = %ld\n", tmp->value);
	if(mouvs)
	{
		if(tmp->pos <= len / 2)
			while (mouvs--)
				rb(pile_b);
		else
			while(mouvs--)
				rrb(pile_b);
	}
}
int chunk_sort(t_list  **pile_b,t_list **pile_a)
{
	t_list	*tmp;
	t_list	*start;
	int		bool;

	start = (*pile_b);
	bool = 1;
	while((*pile_b)->next)
	{
		tmp = (*pile_b);
		if(tmp->index < (*pile_b)->next->index)
		{
			bool = 0;
			break ;
		}
		(*pile_b) = (*pile_b)->next;

	}
	(*pile_b) = start;
	if(bool)
		return(bool);
	get_idsort(pile_b);
	get_pos(pile_b);
	get_best_cost(pile_b);
	set_big_up(pile_b);
	pa(pile_b, pile_a);
	ra(pile_a);
	return(bool);
}

int	sort_first_half(t_list **pile_a, t_list **pile_b, int nb_push, int size)
{
	int		half;
	int		quarter;

	half = size / 2;
	quarter = half / 2;
	if((*pile_a)->index == size)
		ra(pile_a);
	else if ((*pile_a)->index > half && (*pile_a)->index <= half + quarter)
	{
		pb(pile_a, pile_b);
		nb_push++;
	}
	else if ((*pile_a)->index > quarter && (*pile_a)->index <= half)
	{
		push_n_swap(pile_a, pile_b);
		nb_push++;
	}
		else
	ra(pile_a);
	return(nb_push);
}

int	sort_scd_half(t_list **pile_a, t_list **pile_b, int nb_push, int size)
{
	int		half;
	int		quarter;

	half = size / 2;
	quarter = half / 2;
	if((*pile_a)->index == size)
		ra(pile_a);
	else if ((*pile_a)->index > half + quarter && (*pile_a)->index <= size)
	{
		pb(pile_a, pile_b);
		nb_push++;
	}
	else
	{
		push_n_swap(pile_a, pile_b);
		nb_push++;
	}
	return(nb_push);
}

void	pre_sort(t_list **pile_a, t_list **pile_b)
{
	int		size;
	int		half;
	int		quarter;
	int		nb_push;
	int		bool;

	size = ft_lstsize((*pile_a));
	half = size / 2;
	quarter = half / 2;
	nb_push = 0;
	bool = 0;
	while(nb_push < size - 1)
	{
		if(nb_push == quarter && !bool)
		{
			bool = chunk_sort(pile_b, pile_a);
			if(!bool)
				nb_push--;
		}
		if(nb_push >= half)
			nb_push = sort_scd_half(pile_a, pile_b, nb_push, size);
		else
			nb_push = sort_first_half(pile_a, pile_b, nb_push, size);

	}
	// if((*pile_a)->index > (*pile_a)->next->index)
	// 	ra(pile_a);
}


// int	calc_pcost(int idx, int pos, int pos_total)
// {	int		cost;
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
// void	get_pcost(t_list **pile)
// {
// 	t_list	*start;
// 	int		pos_total;

// 	start = (*pile);
// 	pos_total = ft_lstlast((*pile))->pos;
// 	while((*pile))
// 	{
// 		(*pile)->p_cost = calc_pcost((*pile)->p_idx, (*pile)->pos, pos_total);
// 		(*pile) = (*pile)->next;
// 	}
// 	(*pile) = start;
// }

void	get_idsort(t_list **pile)
{
	t_list	*start;
	t_list	*tmp;

	start = (*pile);
	while ((*pile))
	{
	tmp = start;
		while (tmp)
		{
			if (tmp->value < (*pile)->value)
				(*pile)->id_sort += 1;
			tmp = tmp->next;
		}
		(*pile) = (*pile)->next;
	}
		(*pile) = start;
}