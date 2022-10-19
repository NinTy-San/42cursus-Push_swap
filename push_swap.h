/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:42 by adohou            #+#    #+#             */
/*   Updated: 2022/10/13 05:24:07 by adohou           ###   ########.fr       */
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
	struct s_list	*next;
} t_list;

// functions ft_lst
t_list	*ft_lstnew(long nb);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
int	ft_lstsize(t_list *lst);
void	ft_lst_free(t_list **pile);

// functions utils
long	ft_atoi(const char *nptr);
t_list	*get_args(int ac, char **av);
int	check_double(t_list *pile_a, int ac);
int	is_int(char *av);
void	write_error(t_list **pile_a);
void	get_index(t_list **pile_a);
void	get_pos(t_list **pile_a);
int		calc_cost(int idx, int pos, int pos_total);
void	get_best_cost(t_list **pile);




// functions mouvs
void	pb(t_list **pile_a, t_list **pile_b);
void	pa(t_list **pile_b, t_list **pile_a);
void	ra(t_list **pile_a);
void	rb(t_list **pile_b);
void	sa(t_list **pile_a);
void	sb(t_list **pile_b);
void	rra(t_list **pile_a);
void	rrb(t_list **pile_a);
void	ss(t_list **pile_a, t_list **pile_b);
void	rr(t_list **pile_a, t_list **pile_b);
void	rrr(t_list **pile_a, t_list **pile_b);

#endif