/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:42 by adohou            #+#    #+#             */
/*   Updated: 2022/11/05 15:37:49 by adohou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long			value;
	int				index;
	int				pos;
	int				cost;
	int				u_cost;
	struct s_list	*next;
}	t_list;

//functions secure (main.c)
void	ft_print_lst(char *msg, t_list *pile);
void	ft_lst_free(t_list **pile);
void	write_error(t_list **pile_a);
int		is_sort(t_list **pile_a);

//functions ft_lst
t_list	*ft_lstnew(long nb);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

//functions parsing
t_list	*get_args(int ac, char **av);
long	ft_atoi(const char *nptr);
int		check_double(t_list *pile_a, int ac);
int		is_int(char *av);

//functions utils
void	get_index(t_list **pile_a);
void	get_pos(t_list **pile_a);
void	get_best_cost(t_list **pile);
void	get_ultimate_cost(t_list **pile_a, t_list **pile_b);

//functions utils 2
int		find_idx(int b_val, t_list **pile_a);
void	set_small_cost_up(t_list **pile);
void	set_idx_up(t_list **pile, int idx);

//functions sort_utils
void	push_n_swap(t_list **pile_a, t_list **pile_b);
int		sort_first_half(t_list **pile_a, t_list **pile_b,
			int nb_push, int size);
int		sort_scd_half(t_list **pile_a, t_list **pile_b, int nb_push, int size);

//functions sort
void	pre_sort(t_list **pile_a, t_list **pile_b);
void	sort_three(t_list **pile_a);
void	sort_five(t_list **pile_a, t_list **pile_b);
void	sort_pile(t_list **pile_a, t_list **pile_b);

//functions mouvs
void	push(t_list **pile_a, t_list **pile_b);
void	swap(t_list **pile_a);
void	rotate(t_list **pile_a);
void	reverse_rotate(t_list **pile_a);

//mouvs a
void	pa(t_list **pile_a, t_list **pile_b);
void	ra(t_list **pile_a);
void	sa(t_list **pile_a);
void	rra(t_list **pile_a);

//mouvs b
void	pb(t_list **pile_a, t_list **pile_b);
void	rb(t_list **pile_b);
void	sb(t_list **pile_b);
void	rrb(t_list **pile_a);

//mouvs a + b
void	ss(t_list **pile_a, t_list **pile_b);
void	rr(t_list **pile_a, t_list **pile_b);
void	rrr(t_list **pile_a, t_list **pile_b);

#endif