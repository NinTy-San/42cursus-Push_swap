#include "push_swap.h"

void	push_n_swap(t_list **pile_a, t_list **pile_b)
{
	pb(pile_a, pile_b);
	rb(pile_b);
}

int	sort_first_half(t_list **pile_a, t_list **pile_b, int nb_push, int size)
{
	int		half;
	int		quarter;

	half = size / 2;
	quarter = half / 2;
	if ((*pile_a)->index == size || (*pile_a)->index == 1)
		ra(pile_a);
	else if ((*pile_a)->index > half && (*pile_a)->index <= half + quarter)
	{
		pb(pile_a, pile_b);
		nb_push++;
	}
	else if ((*pile_a)->index > quarter && (*pile_a)->index <= half)
	{
		push_n_swap(pile_a, pile_b);
		nb_push++;
	}
	else
		ra(pile_a);
	return (nb_push);
}

int	sort_scd_half(t_list **pile_a, t_list **pile_b, int nb_push, int size)
{
	int		half;
	int		quarter;

	half = size / 2;
	quarter = half / 2;
	if ((*pile_a)->index == size || (*pile_a)->index == 1)
		ra(pile_a);
	else if ((*pile_a)->index > half + quarter && (*pile_a)->index <= size)
	{
		pb(pile_a, pile_b);
		nb_push++;
	}
	else
	{
		push_n_swap(pile_a, pile_b);
		nb_push++;
	}
	return (nb_push);
}
