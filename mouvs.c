/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:51:30 by adohou            #+#    #+#             */
/*   Updated: 2022/09/27 18:57:43 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sa()
// {
// 	if (ft_lstsize(&lst) < 2)
// 		return ;

// }

void pb(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (ft_lstsize((*pile_a)) < 2)
		return ;
	tmp = (*pile_a)->next;
	(*pile_a)->next = NULL;
	ft_lstadd_front((pile_b), (*pile_a));
	(*pile_a) = tmp;
}

void pa(t_list **pile_b, t_list **pile_a)
{
	t_list	*tmp;

	if (ft_lstsize((*pile_b)) < 2)
		return ;
	tmp = (*pile_b)->next;
	(*pile_b)->next = NULL;
	ft_lstadd_front((pile_a), (*pile_b));
	(*pile_b) = tmp;
}