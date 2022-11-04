/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:39:55 by adohou            #+#    #+#             */
/*   Updated: 2022/11/04 18:03:23 by adohou           ###   ########.fr       */
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
		(*pile_a)->index = 1;
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


void	get_pos(t_list **pile)
{
	t_list	*start;
	int		p;

	p = 1;
	start = (*pile);
	while((*pile))
	{
		(*pile)->pos = p++;
		(*pile) = (*pile)->next;
	}
	(*pile) = start;

}
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

int	sort_scd_half(t_list **pile_a, t_list **pile_b, int nb_push, int size)
{
	int		half;
	int		quarter;

	half = size / 2;
	quarter = half / 2;
	if((*pile_a)->index == size || (*pile_a)->index == 1)
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

int	sort_first_half(t_list **pile_a, t_list **pile_b, int nb_push, int size)
{
	int		half;
	int		quarter;

	half = size / 2;
	quarter = half / 2;
	if((*pile_a)->index == size || (*pile_a)->index == 1)
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

void	set_idx_up(t_list **pile, int idx)
{
	t_list	*start;
	int		len;
	int		mouvs;
	int		pos;

	start = (*pile);
	len = ft_lstsize((*pile));
	while ((*pile)->index != idx)
		(*pile) = (*pile)->next;

	mouvs = (*pile)->cost;
	pos = (*pile)->pos;
	(*pile) = start;
	if(mouvs)
	{
		if(pos <= len / 2)
			while (mouvs--)
				ra(pile);
		else
			while(mouvs--)
				rra(pile);
	}
}
void	set_small_cost_up(t_list **pile)
{
	t_list	*start;
	t_list	*tmp;
	t_list	*smallest;
	int		len;
	int		mouvs;

	start = (*pile);
	len = ft_lstsize((*pile));
	smallest = (*pile);
	while ((*pile))
	{
		tmp = start;
		while(tmp)
		{
			if( tmp->u_cost <= smallest->u_cost )
				smallest = tmp;
			tmp = tmp->next;
		}
		(*pile) = (*pile)->next;
	}
	(*pile) = start;
	mouvs = smallest->cost;
	if(mouvs)
	{
		if(smallest->pos <= len / 2)
			while (mouvs--)
				rb(pile);
		else
			while(mouvs--)
				rrb(pile);
	}
}


int		find_idx(int b_idx, t_list **pile_a)
{
	t_list	*start;
	int		tmp;

	start = (*pile_a);
	tmp = 0;
	while((*pile_a))
	{
		if((*pile_a)->index > b_idx && ((*pile_a)->index < tmp|| !tmp))
			tmp = (*pile_a)->index;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start;
	return(tmp);
}

void		get_ultimate_cost(t_list **pile_a, t_list **pile_b)
{
	t_list	*start_a;
	t_list	*start_b;


	start_b = (*pile_b);
	while(*pile_b)
	{
		start_a = (*pile_a);
		while((*pile_a)->index != find_idx((*pile_b)->index, pile_a))
			(*pile_a) = (*pile_a)->next;
		(*pile_b)->u_cost = (*pile_a)->cost + (*pile_b)->cost;
		(*pile_b) = (*pile_b)->next;
		(*pile_a) = start_a;
	}
	(*pile_b) = start_b;
}


void	pre_sort(t_list **pile_a, t_list **pile_b)
{
	int		size;
	int		half;
	int		nb_push;

	size = ft_lstsize((*pile_a));
	half = size / 2;
	nb_push = 0;
	while(nb_push < half)
	{
		if(nb_push >= half)
			nb_push = sort_scd_half(pile_a, pile_b, nb_push, size);
		else
			nb_push = sort_first_half(pile_a, pile_b, nb_push, size);
	}
	while(nb_push < size - 2)
	{
		if(nb_push >= half)
			nb_push = sort_scd_half(pile_a, pile_b, nb_push, size);
		else
			nb_push = sort_first_half(pile_a, pile_b, nb_push, size);
	}
}

void	sort_pile(t_list **pile_a, t_list **pile_b)
{
	int	len;
	len = ft_lstsize((*pile_b));
	while(len--)
	{
		get_pos(pile_a);
		get_pos(pile_b);
		get_best_cost(pile_a);
		get_best_cost(pile_b);
		get_ultimate_cost(pile_a, pile_b);
		get_best_cost(pile_a);
		set_small_cost_up(pile_b);
		set_idx_up(pile_a, find_idx((*pile_b)->index, pile_a));
		pa(pile_a, pile_b);
	}
		get_pos(pile_a);
		get_best_cost(pile_a);
		set_idx_up(pile_a, 1);

}
void	sort_three(t_list **pile_a)
{

	if((*pile_a)->index == 1)
	{
		rra(pile_a);
		sa(pile_a);
	}
	else if((*pile_a)->index == 2)
	{
		if((*pile_a)->next->index == 1)
			sa(pile_a);
		else
			rra(pile_a);
	}
	else if((*pile_a)->index == 3)
	{
		if((*pile_a)->next->index == 1)
			ra(pile_a);
		else
		{
			sa(pile_a);
			rra(pile_a);
		}
	}
	// ft_print_lst("-------------\nend of sort_three =\n", (*pile_a));
	// if(is_sort(pile_a))
	// 	printf("\x1b[32;1mOK\x1b[0m\n");
	// else
	// 	printf("\x1b[31;1mNOK\x1b[0m\n");
}
void	sort_five(t_list **pile_a, t_list **pile_b)
{
	t_list	*start;
	int		cost_id1;
	int		cost_id5;

	get_pos(pile_a);
	get_best_cost(pile_a);
	start = (*pile_a);
	while((*pile_a))
	{
		if((*pile_a)->index == 1)
			cost_id1 = (*pile_a)->cost;
		if((*pile_a)->index == 5)
			cost_id5 = (*pile_a)->cost;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start ;
	if(cost_id1 < cost_id5)
	{
		set_idx_up(pile_a, 1);
		pb(pile_a, pile_b);
		get_index(pile_a);
		get_pos(pile_a);
		get_best_cost(pile_a);
		set_idx_up(pile_a, 4);
		pb(pile_a, pile_b);
	}
	else
	{
		set_idx_up(pile_a, 5);
		pb(pile_a, pile_b);
		get_index(pile_a);
		get_pos(pile_a);
		get_best_cost(pile_a);
		set_idx_up(pile_a, 1);
		pb(pile_a, pile_b);
		get_index(pile_a);
	}
	sort_three(pile_a);
	if((*pile_b)->value < (*pile_b)->next->value)
	{
		pa(pile_a, pile_b);
		pa(pile_a, pile_b);
		ra(pile_a);
	}
	else
	{
		pa(pile_a, pile_b);
		ra(pile_a);
		pa(pile_a, pile_b);
	}
	// ft_print_lst("-------------\nend of sort_five =\n", (*pile_a));
	// if(is_sort(pile_a))
	// 	printf("\x1b[32;1mOK\x1b[0m\n");
	// else
	// 	printf("\x1b[31;1mNOK\x1b[0m\n");
}

int		is_sort(t_list **pile_a)
{
	t_list	*start;
	t_list	*tmp;

	start = (*pile_a);
	tmp = (*pile_a)->next;
	while(tmp && tmp->value > (*pile_a)->value)
	{
		tmp = tmp->next;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start;
	if(!tmp)
		return (1);
	else
		return (0);
}