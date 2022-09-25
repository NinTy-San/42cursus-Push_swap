/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:42 by adohou            #+#    #+#             */
/*   Updated: 2022/09/25 21:29:33 by adohou           ###   ########.fr       */
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




typedef struct s_list
{
	int				value;
	struct s_list	*next;
} t_list;

// typedef struct s_list_pile
// {
// 	t_list	pile_a;
// 	t_list	pile_b;
// } t_list_pile;




t_list	*ft_lstnew(int nb);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
int	ft_lstsize(t_list *lst);

int	ft_atoi(const char *nptr);

#endif