/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:58:31 by adohou            #+#    #+#             */
/*   Updated: 2022/11/04 19:00:06 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **pile_a, t_list **pile_b)
{
	push(pile_b, pile_a);
	write(1, "pa\n", 3);
}

void	sa(t_list **pile_a)
{
	swap(pile_a);
	write(1, "sa\n", 3);
}

void	ra(t_list **pile_a)
{
	rotate(pile_a);
	write(1, "ra\n", 3);
}

void	rra(t_list **pile_a)
{
	reverse_rotate(pile_a);
	write(1, "rra\n", 4);
}
