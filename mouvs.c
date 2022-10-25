/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:51:30 by adohou            #+#    #+#             */
/*   Updated: 2022/10/13 03:24:21 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* functions */
void	push(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (ft_lstsize((*pile_a)) < 1)
		return ;
	tmp = (*pile_a)->next;
	(*pile_a)->next = NULL;
	ft_lstadd_front(pile_b, (*pile_a));
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

/*simple mouv */
void	pa(t_list **pile_b, t_list **pile_a)
{
	push(pile_b, pile_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **pile_a, t_list **pile_b)
{
	push(pile_a, pile_b);
	write(1, "pb\n", 3);
}

void	sa(t_list **pile_a)
{
	swap(pile_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **pile_b)
{
	swap(pile_b);
	write(1, "sb\n", 3);
}

void	ra(t_list **pile_a)
{
	rotate(pile_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **pile_b)
{
	rotate(pile_b);
	write(1, "rb\n", 3);
}

void	rra(t_list **pile_a)
{
	reverse_rotate(pile_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **pile_b)
{
	reverse_rotate(pile_b);
	write(1, "rrb\n", 4);
}

/* double mouvs */
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
