/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:42 by adohou            #+#    #+#             */
/*   Updated: 2022/09/27 23:01:36 by adohou           ###   ########.fr       */
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
	long				value;
	struct s_list	*next;
} t_list;

// typedef struct s_list_pile
// {
// 	t_list	pile_a;
// 	t_list	pile_b;
// } t_list_pile;



// functions ft_lst
t_list	*ft_lstnew(long nb);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
int	ft_lstsize(t_list *lst);
void	ft_lst_free(t_list **pile);

// functions utils
long	ft_atoi(const char *nptr);
int	*get_args(int ac, char **av);
int	check_int_args(int *args);
int	is_int(char *av);

// functions mouvs
void pb(t_list **pile_a, t_list **pile_b);
void pa(t_list **pile_b, t_list **pile_a);


#endif