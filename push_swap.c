/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/09/26 18:39:14 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	t_list	*pile_a;
	t_list	*new;
	int		*args;
	int		i;

	i = 0;
	pile_a = NULL;

	args = get_args(ac, av);
	if(!args)
	{
		free(args);
		printf("Error!");
		return (0);
	}
	while (args[i])
	{
		new = ft_lstnew(args[i]);
		// printf("->new = %ld\n", new->value);
		if (!new)
			return (0);
		ft_lstadd_back(&pile_a, new);
		i++;
	}
	while(pile_a)
	{
		printf("%ld ", pile_a->value);
		pile_a = pile_a->next;
	}

	return (0);
}

// int main ()
// {
// 	pile	*lst;
// 	pile 	*new;
// 	int 	nbr;
// 	int		nbr2;

// 	nbr = 42;
// 	nbr2 = 24;
// 	lst = ft_lstnew(nbr);
// 	new = ft_lstnew(nbr2);
// 	ft_lstadd_back(&lst, new);
// 	// printf("%d", lst->nb);
// 	while(lst)
// 	{
// 		printf("%d ", lst->value);
// 		lst = lst->next;
// 	}
// 	return (0);
// }