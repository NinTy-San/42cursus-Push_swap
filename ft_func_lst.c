/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:21:21 by adohou            #+#    #+#             */
/*   Updated: 2022/09/25 21:59:14 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list		*lst;

	lst = malloc(sizeof(lst));
	if (!lst)
		return (NULL);
	lst->value = value;

	lst->next = NULL;
	return (lst);
}


t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		tmp = ft_lstlast((*lst));
		tmp->next = new;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	(*del)(lst->value);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*tmp;

	tmp = NULL;
	while ((*lst))
	{
		tmp = *lst;
		(*del)((*lst)->value);
		(*lst)= (*lst)->next;
		free(tmp);
	}
	free(*lst);
	(*lst) = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
