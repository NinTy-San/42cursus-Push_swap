/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/09/20 19:21:43 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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