#include "push_swap.h"

void	pre_sort(t_list **pile_a, t_list **pile_b)
{
	int		size;
	int		half;
	int		nb_push;

	size = ft_lstsize((*pile_a));
	half = size / 2;
	nb_push = 0;
	while(nb_push < half)
	{
		if(nb_push >= half)
			nb_push = sort_scd_half(pile_a, pile_b, nb_push, size);
		else
			nb_push = sort_first_half(pile_a, pile_b, nb_push, size);
	}
	while(nb_push < size - 2)
	{
		if(nb_push >= half)
			nb_push = sort_scd_half(pile_a, pile_b, nb_push, size);
		else
			nb_push = sort_first_half(pile_a, pile_b, nb_push, size);
	}
}

void	sort_three(t_list **pile_a)
{

	if((*pile_a)->index == 1)
	{
		rra(pile_a);
		sa(pile_a);
	}
	else if((*pile_a)->index == 2)
	{
		if((*pile_a)->next->index == 1)
			sa(pile_a);
		else
			rra(pile_a);
	}
	else if((*pile_a)->index == 3)
	{
		if((*pile_a)->next->index == 1)
			ra(pile_a);
		else
		{
			sa(pile_a);
			rra(pile_a);
		}
	}
	// ft_print_lst("-------------\nend of sort_three =\n", (*pile_a));
	// if(is_sort(pile_a))
	// 	printf("\x1b[32;1mOK\x1b[0m\n");
	// else
	// 	printf("\x1b[31;1mNOK\x1b[0m\n");
}

void	sort_five(t_list **pile_a, t_list **pile_b)
{
	t_list	*start;
	int		cost_id1;
	int		cost_id5;

	get_pos(pile_a);
	get_best_cost(pile_a);
	start = (*pile_a);
	while((*pile_a))
	{
		if((*pile_a)->index == 1)
			cost_id1 = (*pile_a)->cost;
		if((*pile_a)->index == 5)
			cost_id5 = (*pile_a)->cost;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start ;
	if(cost_id1 < cost_id5)
	{
		set_idx_up(pile_a, 1);
		pb(pile_a, pile_b);
		get_index(pile_a);
		get_pos(pile_a);
		get_best_cost(pile_a);
		set_idx_up(pile_a, 4);
		pb(pile_a, pile_b);
	}
	else
	{
		set_idx_up(pile_a, 5);
		pb(pile_a, pile_b);
		get_index(pile_a);
		get_pos(pile_a);
		get_best_cost(pile_a);
		set_idx_up(pile_a, 1);
		pb(pile_a, pile_b);
		get_index(pile_a);
	}
	sort_three(pile_a);
	if((*pile_b)->value < (*pile_b)->next->value)
	{
		pa(pile_a, pile_b);
		pa(pile_a, pile_b);
		ra(pile_a);
	}
	else
	{
		pa(pile_a, pile_b);
		ra(pile_a);
		pa(pile_a, pile_b);
	}
	// ft_print_lst("-------------\nend of sort_five =\n", (*pile_a));
	// if(is_sort(pile_a))
	// 	printf("\x1b[32;1mOK\x1b[0m\n");
	// else
	// 	printf("\x1b[31;1mNOK\x1b[0m\n");
}

void	sort_pile(t_list **pile_a, t_list **pile_b)
{
	int	len;
	len = ft_lstsize((*pile_b));
	while(len--)
	{
		get_pos(pile_a);
		get_pos(pile_b);
		get_best_cost(pile_a);
		get_best_cost(pile_b);
		get_ultimate_cost(pile_a, pile_b);
		get_best_cost(pile_a);
		set_small_cost_up(pile_b);
		set_idx_up(pile_a, find_idx((*pile_b)->index, pile_a));
		pa(pile_a, pile_b);
	}
		get_pos(pile_a);
		get_best_cost(pile_a);
		set_idx_up(pile_a, 1);

}