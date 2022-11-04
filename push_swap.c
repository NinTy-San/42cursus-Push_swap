/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/11/03 19:00:54 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void ft_print_lst(char *msg, t_list *pile)
{
	t_list	*start;

	start = pile;
	printf("%s", msg);
	while(pile)
	{
		printf("val = %ld | idx = %d | pos = %d | cost = %d \n", pile->value, pile->index, pile->pos, pile->cost);
		pile = pile->next;
	}
	pile = start;
} */

void ft_print_lst(char *msg, t_list *pile)
{
	t_list    *start;

	start = pile;
	printf("%s", msg);
	while(pile)
	{
		printf("val = ");
		if (pile->value <= 99)
			printf(" ");
		if (pile->value <= 9)
			printf(" ");
		printf("\x1b[31;1m%ld\x1b[0m", pile->value);
		printf(" | idx = ");
		if (pile->index <= 99)
			printf(" ");
		if (pile->index <= 9)
			printf(" ");
		printf("\x1b[32;1m%d\x1b[0m", pile->index);
		printf(" | pos = ");
		if (pile->pos <= 99)
			printf(" ");
		if (pile->pos <= 9)
			printf(" ");
		printf("\x1b[33;1m%d\x1b[0m", pile->pos);
		printf(" | cost = ");
		if (pile->cost <= 99)
			printf(" ");
		if (pile->cost <= 9)
			printf(" ");
		printf("\x1b[34;1m%d\x1b[0m", pile->cost);
		printf(" | ultimate_cost = ");
		if (pile->u_cost <= 99)
			printf(" ");
		if (pile->u_cost <= 9)
			printf(" ");
		printf("\x1b[35;1m%d\x1b[0m", pile->u_cost);
		printf(" \n");
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
	if (ac <= 2)
		return (0);
	pile_a = get_args(ac , av);
	if (!pile_a || is_sort(&pile_a))
		return (0);
	get_index(&pile_a);
	if (ft_lstsize(pile_a) == 3)
	{
		sort_three(&pile_a);
		return (0);
	}
	if (ft_lstsize(pile_a) == 5)
	{
		sort_five(&pile_a, &pile_b);
		return (0);
	}
	pre_sort(&pile_a, &pile_b);
	sort_pile(&pile_a, &pile_b);

	ft_print_lst("pile_a = \n", pile_a);

	if(is_sort)
		printf("\x1b[32;1mOK\x1b[0m\n");
	else
		printf("\x1b[31;1mNOK\x1b[0m\n");
	// ft_print_lst("pile_b = \n", pile_b);

	ft_lst_free(&pile_a);
	ft_lst_free(&pile_b);
	return (0);
}