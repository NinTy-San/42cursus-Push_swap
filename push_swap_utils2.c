/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:07:52 by adohou            #+#    #+#             */
/*   Updated: 2022/11/05 15:28:42 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_idx(int b_idx, t_list **pile_a)
{
	t_list	*start;
	int		tmp;

	start = (*pile_a);
	tmp = 0;
	while ((*pile_a))
	{
		if ((*pile_a)->index > b_idx && ((*pile_a)->index < tmp || !tmp))
			tmp = (*pile_a)->index;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start;
	return (tmp);
}

static void	rotate_small_cost_up(t_list **pile, int mouvs, int pos, int len)
{
	if (mouvs)
	{
		if (pos <= len / 2)
			while (mouvs--)
				rb(pile);
		else
			while (mouvs--)
				rrb(pile);
	}
}

void	set_small_cost_up(t_list **pile)
{
	t_list	*start;
	t_list	*tmp;
	t_list	*smallest;
	int		len;

	start = (*pile);
	len = ft_lstsize((*pile));
	smallest = (*pile);
	while ((*pile))
	{
		tmp = start;
		while (tmp)
		{
			if (tmp->u_cost <= smallest->u_cost)
				smallest = tmp;
			tmp = tmp->next;
		}
		(*pile) = (*pile)->next;
	}
	(*pile) = start;
	rotate_small_cost_up(pile, smallest->cost, smallest->pos, len);
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
	if (mouvs)
	{
		if (pos <= len / 2)
			while (mouvs--)
				ra(pile);
		else
			while (mouvs--)
				rra(pile);
	}
}
