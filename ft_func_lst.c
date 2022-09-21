/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:21:21 by adohou            #+#    #+#             */
/*   Updated: 2022/09/21 22:54:49 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

pile	*ft_lstnew(int value)
{
	pile		*lst;

	lst = malloc(sizeof(pile));
	if (!lst)
		return (NULL);
	(*lst)->value = value;

	(*lst)->next = NULL;
	return (lst);
}
pile	new_pile(void)
{
	return NULL ;
}

pile	*ft_lstlast(pile *lst)
{
	if (!lst)
		return (NULL);
	while ((*lst)->next)
		lst = (*lst)->next;
	return (lst);
}

void	ft_lstadd_back(pile **lst, pile *new)
{
	pile	*tmp;

	if (!lst || !new)
		return ;
	if (!(lst))
		*lst = new;
	else
	{
		tmp = ft_lstlast((*lst));
		(*tmp)->next = new;
	}
}

void	ft_lstdelone(pile *lst, void (*del)(int))
{
	(*del)((*lst)->value);
	free(lst);
}

void	ft_lstclear(pile **lst, void (*del)(int))
{
	pile	*tmp;

	tmp = NULL;
	while ((*lst))
	{
		tmp = *lst;
		(*del)((**lst)->value);
		(*lst) = (**lst)->next;
		free(tmp);
	}
	free(*lst);
	(*lst) = NULL;
}

void	ft_lstadd_front(pile **lst, pile *new)
{
	if (!new || !lst)
		return ;
	(*new)->next = *lst;
	*lst = new;
}

int	ft_lstsize(pile *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = (*lst)->next;
	}
	return (i);
}



