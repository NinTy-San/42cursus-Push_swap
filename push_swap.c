/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:19 by adohou            #+#    #+#             */
/*   Updated: 2022/11/09 21:30:41 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(t_list **pile_a)
{
	ft_lst_free(pile_a);
	write(2, "Error\n", 6);
}

int	is_sort(t_list **pile_a)
{
	t_list	*start;
	t_list	*tmp;

	start = (*pile_a);
	tmp = (*pile_a)->next;
	while (tmp && tmp->value > (*pile_a)->value)
	{
		tmp = tmp->next;
		(*pile_a) = (*pile_a)->next;
	}
	(*pile_a) = start;
	if (!tmp)
		return (1);
	else
		return (0);
}

void	ft_lst_free(t_list **pile)
{
	t_list	*tmp;

	tmp = NULL;
	if (pile)
	{
		while ((*pile))
		{
			tmp = (*pile)->next;
			free((*pile));
			(*pile) = tmp;
		}
	}
}

void	ft_lst_free2(t_list **pile_a, t_list **pile_b)
{
	if (pile_a)
		ft_lst_free(pile_a);
	if (pile_b)
		ft_lst_free(pile_b);
}

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	// int		size;

	pile_a = NULL;
	pile_b = NULL;
	pile_a = get_args(ac, av);
	if (!pile_a || is_sort(&pile_a))
		return (ft_lst_free(&pile_a), 0);
	get_index(&pile_a);
	if (ft_lstsize(pile_a) == 2)
	{
		sa(&pile_a);
		return (ft_lst_free(&pile_a), 0);
	}
	if (ft_lstsize(pile_a) == 3)
		return (sort_three(&pile_a), 0);
	if (ft_lstsize(pile_a) == 5)
		return (sort_five(&pile_a, &pile_b), 0);
	pre_sort(&pile_a, &pile_b);
	sort_pile(&pile_a, &pile_b);
	ft_lst_free2(&pile_a, &pile_b);
	return (0);
}
