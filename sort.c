/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:08:16 by adohou            #+#    #+#             */
/*   Updated: 2022/11/10 19:09:17 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(t_list **pile_a, t_list **pile_b)
{
	int		size;
	int		half;
	int		nb_push;

	size = ft_lstsize((*pile_a));
	half = size / 2;
	nb_push = 0;
	while (nb_push < half)
	{
		if (nb_push >= half)
			nb_push = sort_scd_half(pile_a, pile_b, nb_push, size);
		else
			nb_push = sort_first_half(pile_a, pile_b, nb_push, size);
	}
	while (nb_push < size - 2)
		nb_push = sort_scd_half(pile_a, pile_b, nb_push, size);
}

void	sort_three(t_list **pile_a)
{
	if (is_sort(pile_a))
		return ;
	if ((*pile_a)->index == 1)
	{
		rra(pile_a);
		sa(pile_a);
	}
	else if ((*pile_a)->index == 2)
	{
		if ((*pile_a)->next->index == 1)
			sa(pile_a);
		else
			rra(pile_a);
	}
	else if ((*pile_a)->index == 3)
	{
		if ((*pile_a)->next->index == 1)
			ra(pile_a);
		else
		{
			sa(pile_a);
			rra(pile_a);
		}
	}
	ft_lst_free(pile_a);
}

void	sort_five(t_list **pile_a, t_list **pile_b)
{
	get_pos(pile_a);
	get_best_cost(pile_a);
	set_idx_up(pile_a, 5);
	pb(pile_a, pile_b);
	get_index(pile_a);
	get_pos(pile_a);
	get_best_cost(pile_a);
	set_idx_up(pile_a, 1);
	pb(pile_a, pile_b);
	get_index(pile_a);
	sort_three(pile_a);
	if ((*pile_b)->value < (*pile_b)->next->value)
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
	ft_lst_free2(pile_a, pile_b);
}

void	sort_pile(t_list **pile_a, t_list **pile_b)
{
	int	len;

	len = ft_lstsize((*pile_b));
	while (len--)
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
