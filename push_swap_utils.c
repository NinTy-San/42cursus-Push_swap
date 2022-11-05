/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninety-san <ninety-san@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:39:55 by adohou            #+#    #+#             */
/*   Updated: 2022/11/05 03:04:08 by ninety-san       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while ((*pile))
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
	while ((*pile))
	{
		if ((*pile)->pos <= pos_total / 2 + 1)
			(*pile)->cost = (*pile)->pos - 1;
		else
			(*pile)->cost = (pos_total - (*pile)->pos + 1);
		(*pile) = (*pile)->next;
	}
	(*pile) = start;
}

void	get_ultimate_cost(t_list **pile_a, t_list **pile_b)
{
	t_list	*start_a;
	t_list	*start_b;

	start_b = (*pile_b);
	while (*pile_b)
	{
		start_a = (*pile_a);
		while ((*pile_a)->index != find_idx((*pile_b)->index, pile_a))
			(*pile_a) = (*pile_a)->next;
		(*pile_b)->u_cost = (*pile_a)->cost + (*pile_b)->cost;
		(*pile_b) = (*pile_b)->next;
		(*pile_a) = start_a;
	}
	(*pile_b) = start_b;
}
