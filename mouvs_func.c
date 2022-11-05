/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:51:30 by adohou            #+#    #+#             */
/*   Updated: 2022/11/04 19:04:32 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (ft_lstsize((*pile_a)) < 1)
		return ;
	tmp = (*pile_a)->next;
	(*pile_a)->next = NULL;
	ft_lstadd_front((pile_b), (*pile_a));
	(*pile_a) = tmp;
}

void	swap(t_list **pile_a)
{
	t_list	*first;
	t_list	*tmp;

	if (ft_lstsize((*pile_a)) < 2)
		return ;
	first = (*pile_a);
	tmp = (*pile_a)->next;
	first->next = tmp->next;
	tmp->next = first;
	(*pile_a) = tmp;
}

void	rotate(t_list **pile_a)
{
	t_list	*first;
	t_list	*tmp;
	t_list	*start;

	if (ft_lstsize((*pile_a)) < 2)
		return ;
	first = (*pile_a);
	tmp = (*pile_a)->next;
	start = tmp;
	tmp = ft_lstlast(tmp);
	tmp->next = first;
	tmp = tmp->next;
	tmp->next = NULL;
	(*pile_a) = start;
}

void	reverse_rotate(t_list **pile_a)
{
	t_list	*first;
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize((*pile_a)) < 2)
		return ;
	first = (*pile_a);
	while ((*pile_a)->next->next)
		(*pile_a) = (*pile_a)->next;
	tmp = (*pile_a);
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	(*pile_a) = last;
}
