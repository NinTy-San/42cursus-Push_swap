/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/10/10 16:07:32 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_lst(char *msg, t_list *pile)
{
	t_list	*start;

	start = pile;
	printf("%s", msg);
	while(pile)
	{
		printf("%ld ", pile->value);
		pile = pile->next;
	}
	pile = start;
}

int main (int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (ac <= 1)
		return (0);
	pile_a = get_args(ac , av);
	if (!pile_a)
		return (0);

	//ft_print_lst("args into pile_a = ", pile_a);

	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	// ft_print_lst("\nafter pb x3 pile_b = ", pile_b);

	pa(&pile_b, &pile_a);
	// ft_print_lst("\nafter pa x1 pile_a = ", pile_a);

	ra(&pile_a);
	// ft_print_lst("\nafter ra pile a = ", pile_a);

	rb(&pile_b);
	// ft_print_lst("\nafter rb pile b = ", pile_b);

	sa(&pile_a);
	// ft_print_lst("\nafter sa pile a = ", pile_a);

	sb(&pile_b);
	// ft_print_lst("\nafter sb pile a = ", pile_b);

	rra(&pile_a);
	// ft_print_lst("\nafter rra pile a = ", pile_a);

	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	// ft_print_lst("\nafter pb x2 pile b = ", pile_b);

	rrb(&pile_b);
	// ft_print_lst("\nafter rra pile b = ", pile_b);

	ft_lst_free(&pile_a);
	ft_lst_free(&pile_b);
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