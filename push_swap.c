/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/10/13 05:26:09 by adohou           ###   ########.fr       */
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
		printf("val = %ld | idx = %d | pos = %d\n", pile->value, pile->index, pile->pos);
		pile = pile->next;
	}
	pile = start;
}

int main (int ac, char **av)
{
	t_list	*pile_a;
	// t_list	*pile_b;

	pile_a = NULL;
	// pile_b = NULL;
	if (ac <= 2)
		return (0);
	pile_a = get_args(ac , av);
	if (!pile_a)
		return (0);
	ft_print_lst("pile a = \n", pile_a);
	get_index(&pile_a);
	printf("-------------\n");
	ft_print_lst("after get_index pile a = \n", pile_a);
	get_pos(&pile_a);
	ft_print_lst("after get_pos pile a = \n", pile_a);
	// pb(&pile_a, &pile_b);
	// ft_print_lst("after pb pile b = \n", pile_b);
	ft_lst_free(&pile_a);
	// ft_lst_free(&pile_b);
	return (0);
}