/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:12:28 by rrodor            #+#    #+#             */
/*   Updated: 2023/05/24 21:45:05 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_intlist	*ps_lstnew(int content)
{
	t_intlist	*init;

	init = malloc(sizeof(t_intlist));
	if (!init)
		return (0);
	init->content = content;
	init->next = 0;
	return (init);
}

void	ps_lstadd_back(t_intlist **lst, t_intlist *new)
{
	t_intlist	*last;

	if (!lst)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		last = ps_lstlast(*lst);
		last->next = new;
	}
}

void	ps_lstadd_front(t_intlist **lst, t_intlist *new)
{
	new->next = *lst;
	*lst = new;
}

void	ps_lstiter(t_intlist *lst, void (*f)(int))
{
	t_intlist	*i;

	if (!lst)
		return ;
	i = lst;
	while (i)
	{
		f(i->content);
		i = i->next;
	}
}

t_intlist	*ps_lstlast(t_intlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
