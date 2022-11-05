/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninety-san <ninety-san@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:00:33 by adohou            #+#    #+#             */
/*   Updated: 2022/11/05 03:08:45 by ninety-san       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **pile_a, t_list **pile_b)
{
	push(pile_a, pile_b);
	write(1, "pb\n", 3);
}

void	sb(t_list **pile_b)
{
	swap(pile_b);
	write(1, "sb\n", 3);
}

void	rb(t_list **pile_b)
{
	rotate(pile_b);
	write(1, "rb\n", 3);
}

void	rrb(t_list **pile_b)
{
	reverse_rotate(pile_b);
	write(1, "rrb\n", 4);
}