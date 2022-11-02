/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/11/02 19:15:45 by adohou           ###   ########.fr       */
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
		printf("val = %ld | idx = %d | pos = %d | id = %d | cost = %d \n", pile->value, pile->index, pile->pos, pile->id_sort, pile->cost);
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
        printf(" | id = ");
        if (pile->id_sort <= 99)
            printf(" ");
        if (pile->id_sort <= 9)
            printf(" ");
        printf("\x1b[34;1m%d\x1b[0m", pile->id_sort);
        printf(" | cost = ");
        if (pile->cost <= 99)
            printf(" ");
        if (pile->cost <= 9)
            printf(" ");
        printf("\x1b[35;1m%d\x1b[0m", pile->cost);
        printf(" \n");
        pile = pile->next;
    }
    pile = start;
}

int main (int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	// int		size;

	pile_a = NULL;
	pile_b = NULL;
	if (ac <= 2)
		return (0);
	pile_a = get_args(ac , av);
	if (!pile_a)
		return (0);
	// ft_print_lst("pile a = \n", pile_a);
	get_index(&pile_a);
	// get_pos(&pile_a);
	// printf("-------------\n");
	// ft_print_lst("after get_index pile a = \n", pile_a);
	// ft_print_lst("after get_pose pile a = \n", pile_a);
	// get_best_cost(&pile_a);
	// ft_print_lst("after get_best_cost pile a = \n", pile_a);
	pre_sort(&pile_a, &pile_b);
	// ft_print_lst("after pre_sort pile b = \n", pile_b);
	// pb(&pile_a, &pile_b);
	// size = ft_lstsize(pile_b);
	// size /= 2;
	// while (size--)
	// {
	// 	pa(&pile_b, &pile_a);
	// }
	// get_pos(&pile_b);
	// get_best_cost(&pile_b);
	get_pos(&pile_a);
	get_pos(&pile_b);
	get_best_cost(&pile_a);
	get_best_cost(&pile_b);
	// ft_print_lst("pile a = \n", pile_a);
	// ft_print_lst("pile b = \n", pile_b);

	// printf("idx finded = %d",find_idx(pile_b->index, &pile_a));
	// get_id_sort(&pile_b);

	ft_lst_free(&pile_a);
	ft_lst_free(&pile_b);
	return (0);
}