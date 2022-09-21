/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adohou <adohou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:44:42 by adohou            #+#    #+#             */
/*   Updated: 2022/09/21 22:50:16 by adohou           ###   ########.fr       */
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


typedef struct s_pile
{
	int			value;
	struct s_pile	*next;
} *pile;



pile	*ft_lstnew(int nb);
pile	*ft_lstlast(pile *lst);
void	ft_lstadd_back(pile **lst, pile *new);
void	ft_lstadd_front(pile **lst, pile *new);
void	ft_lstdelone(pile *lst, void (*del)(int));
void	ft_lstclear(pile **lst, void (*del)(int));
int	ft_lstsize(pile *lst);

#endif