/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:18:15 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/14 13:36:24 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_point
{
	int	size1;
	int	size2;
}	t_point;

typedef struct s_intlist
{
	int					content;
	struct s_intlist	*next;
}	t_intlist;

typedef struct s_size
{
	int	stab;
	int	spart;
	int	*tab;
}	t_size;

int			testatoi(char *str);
void		ft_printlst(int n);
void		ps_swap(t_intlist *lsta, t_intlist *lstb, char c);
void		ps_push(t_intlist **la, t_intlist **lb, char c);
void		ps_rotate(t_intlist **la, t_intlist **lb, char c);
void		ps_revrotate(t_intlist **la, t_intlist **lb, char c);
void		ft_pushswap(t_intlist **la, t_intlist **lb);
int			checkolst(t_intlist **la, int *d);
int			checkrevolst(t_intlist **la, int *d);
t_intlist	*ft_lstlastlast(t_intlist *lst);
int			*ft_reftab(t_intlist **la, int *size);
t_intlist	*ps_lstnew(int content);
void		ps_lstadd_back(t_intlist **lst, t_intlist *new);
void		ps_lstadd_front(t_intlist **lst, t_intlist *new);
void		ps_lstiter(t_intlist *lst, void (*f)(int));
t_intlist	*ps_lstlast(t_intlist *lst);
int			ps_lstsize(t_intlist *lst);
void		ps_dividebis(t_intlist **la, t_intlist **lb, t_size size, int i);
int			ft_shortpath(t_intlist **la, int *tab, int size, int part);
void		ft_ifswap(t_intlist **la, t_intlist **lb);
void		ft_tri(t_intlist **la, t_intlist **lb, int *tab, t_size size);
int			ft_inorder(t_intlist **la, int *p);
void		ft_sort(t_intlist **la, t_intlist **lb);
int			ft_eighthoccur(t_intlist **l);
t_intlist	*ps_lstelem(t_intlist **la, int i);
void		ps_quicksort(t_intlist **la, t_intlist **lb, int *tab, int size);
void		bruteforce3(t_intlist **la, t_intlist **lb);
void		bruteforce3v2(t_intlist **la, t_intlist **lb);
void		bruteforce3v2p2(t_intlist **la, t_intlist **lb);
void		bruteforce2(t_intlist **la, t_intlist **lb);
int			ps_getmed(t_intlist **la, int *tab, int size);
void		ps_divide1(t_intlist **la, t_intlist **lb, int *tab, t_size size);
void		ps_divide2(t_intlist **la, t_intlist **lb, int *tab, t_size size);
void		ps_divide(t_intlist **la, t_intlist **lb, int *tab, t_size size);
int			ft_inorder2(t_intlist **la, int start, int end);
void		bruteforce5(t_intlist **la, t_intlist **lb);
void		bruteforce5p2(t_intlist **la, t_intlist **lb, int min);
int			bruteforce5bis(int i, int j, int k, t_intlist *t);
void		bruteforce4p2(t_intlist **la, t_intlist **lb, int min);
void		bruteforce4(t_intlist **la, t_intlist **lb);
int			bf5_last(t_intlist **la);
void		ps_quicksortp1(t_intlist **la, t_intlist **lb, int med, int size);
void		ps_quicksortp2(t_intlist **la, t_intlist **lb, int s1, int s2);
void		ps_quicksortp3(t_intlist **la, t_intlist **lb, t_point s, int *tab);
int			ps_shortsort(t_intlist **la, t_intlist **lb, int *tab, int size1);
int			ps_islstvalid(int argc, char **argv);
int			ft_reftab2(t_intlist **la, int *j, int *size);
void		ps_lstclear(t_intlist **lst);
void		ps_lstdelone(t_intlist *lst);
void		bruteforce5shortp2(t_intlist **la, t_intlist **lb, int min);
void		bruteforce5short(t_intlist **la, t_intlist **lb);
int			ps_countwrd(const char *s, char c);
int			ps_splitinit(char const *s, char c, int *i, int *j);
char		**ps_split(char const *s, char c, int *argc);
char		*ps_name(void);
int			ps_free(t_intlist **la, char **argv, int j);

#endif
