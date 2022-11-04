/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:03:27 by adohou            #+#    #+#             */
/*   Updated: 2022/11/04 19:04:36 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **pile_a, t_list **pile_b)
{
	swap(pile_a);
	swap(pile_b);
	write(1, "ss\n", 3);
}

void rr(t_list **pile_a, t_list **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	write(1, "rr\n", 3);
}

void rrr(t_list **pile_a, t_list **pile_b)
{
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
	write(1, "rrr\n", 4);
}