/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:51:30 by adohou            #+#    #+#             */
/*   Updated: 2022/11/10 19:26:43 by adohou           ###   ########.fr       */
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

void	rotate(t_list **pile)
{
	t_list	*first;
	t_list	*tmp;
	t_list	*start;

	if (ft_lstsize((*pile)) < 2)
		return ;
	first = (*pile);
	tmp = (*pile)->next;
	start = tmp;
	tmp = ft_lstlast(tmp);
	tmp->next = first;
	tmp = tmp->next;
	tmp->next = NULL;
	(*pile) = start;
}

void	reverse_rotate(t_list **pile)
{
	t_list	*first;
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize((*pile)) < 2)
		return ;
	first = (*pile);
	while ((*pile)->next->next)
		(*pile) = (*pile)->next;
	tmp = (*pile);
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	(*pile) = last;
}

void	swap(t_list **pile)
{
	t_list	*first;
	t_list	*tmp;

	if (ft_lstsize((*pile)) < 2)
		return ;
	first = (*pile);
	tmp = (*pile)->next;
	first->next = tmp->next;
	tmp->next = first;
	(*pile) = tmp;
}
