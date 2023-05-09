/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:18:15 by rrodor            #+#    #+#             */
/*   Updated: 2023/05/05 18:36:24 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft.h"

# define SIZEPART 8

typedef struct s_intlist
{
	int				content;
	struct s_intlist	*next;
}	t_intlist;

int			testatoi(char *str);
void		ft_printlst(int n);
void		ps_swap(t_intlist *lsta, t_intlist *lstb, char c);
void		ps_push(t_intlist **la, t_intlist **lb, char c);
void		ps_rotate(t_intlist **la, t_intlist **lb, char c);
void		ps_revrotate(t_intlist **la, t_intlist **lb, char c);
void		ft_pushswap(t_intlist **la, t_intlist **lb);
int			checkolst(t_intlist **la, int *d);
int     	checkrevolst(t_intlist **la, int *d);
t_intlist	*ft_lstlastlast(t_intlist *lst);
int			*ft_reftab(t_intlist **la, int *size);
t_intlist	*ps_lstnew(int content);
void		ps_lstadd_back(t_intlist **lst, t_intlist *new);
void		ps_lstadd_front(t_intlist **lst, t_intlist *new);
void		ps_lstiter(t_intlist *lst, void (*f)(int));
t_intlist	*ps_lstlast(t_intlist *lst);
int			ps_lstsize(t_intlist *lst);
void		**ft_divide(t_intlist **la, t_intlist **lb, int part, int *tab, int size);
int			ft_shortpath(t_intlist **la, int *tab, int size, int part);
void		ft_ifswap(t_intlist **la,t_intlist **lb);
void		ft_tri(t_intlist **la, t_intlist **lb, int *tab, int size, int max);
int			ft_inorder(t_intlist **la, int *p);
void		ft_sort(t_intlist **la, t_intlist **lb);
int			ft_eighthoccur(t_intlist **l);
t_intlist	*ps_lstelem(t_intlist **la, int i);

#endif
