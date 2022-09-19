/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/09/19 21:38:36 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nb)
{
	t_list		*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->nb = nb;

	lst->next = NULL;
	return (lst);
}

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!new || !lst)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }
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
	if (!(lst))
		*lst = new;
	else
	{
		tmp = ft_lstlast((*lst));
		tmp->next = new;
	}
}


int main ()
{
	t_list	*lst;
	t_list 	*new;
	int 	nbr;
	int		nbr2;

	nbr = 42;
	nbr2 = 24;
	lst = ft_lstnew(nbr);
	new = ft_lstnew(nbr2);
	ft_lstadd_back(&lst, new);
	// printf("%d", lst->nb);
	while(lst)
	{
		printf("%d ", lst->nb);
		lst = lst->next;
	}
	return (0);
}