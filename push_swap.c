/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/10/04 21:14:01 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*start_a;
	t_list	*start_b;

	// int		*args;
	// int		i;

	// i = 0;
	pile_a = NULL;
	pile_b = NULL;
	if (ac <= 1)
		return (0);
	pile_a = get_args(pile_a, ac, av);
	if (!pile_a)
		return (0);

	start_a = pile_a;
	printf("args into pile_a");
	while(pile_a)
	{
		printf("%ld ", pile_a->value);
		pile_a = pile_a->next;
	}
	pile_a = start_a;
	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	printf("pile_b = ");
	start_b = pile_b;
	while(pile_b)
	{
		printf("%ld ", pile_b->value);
		pile_b = pile_b->next;
	}
	pile_b = start_b;
	printf("\n");
	pa(&pile_b, &pile_a);
	printf("pile_a = ");
	start_a = pile_a;
	while(pile_a)
	{
		printf("%ld ", pile_a->value);
		pile_a = pile_a->next;
	}
	pile_a = start_a;
	ra(&pile_a);
	printf("\nprint after ra\n");
	while(pile_a)
	{
		printf("%ld ", pile_a->value);
		pile_a = pile_a->next;
	}

	ft_lst_free(&pile_a);
	ft_lst_free(&pile_b);
	// free(args);
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