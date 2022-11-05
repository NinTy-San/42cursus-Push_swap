#include "push_swap.h"

void	ft_print_lst(char *msg, t_list *pile)
{
	t_list	*start;
	start = pile;
	printf("%s", msg);
	while (pile)
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
	if (is_sort(&pile))
		printf("\x1b[32;1mSort:OK\x1b[0m\n");
	else
		printf("\x1b[31;1mNSort/KO\x1b[0m\n");
}
