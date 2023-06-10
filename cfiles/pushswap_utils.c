/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:46:18 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/09 16:43:52 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	testatoi(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_inorder2(t_intlist **la, int start, int end)
{
	t_intlist	*l;
	int			i;

	i = end;
	l = ps_lstelem(la, i - 1);
	while (i >= start)
	{
		if (l->content > l->next->content)
			return (1);
		l = ps_lstelem(la, i - 1);
		i--;
	}
	return (0);
}

t_intlist	*ps_lstelem(t_intlist **la, int i)
{
	t_intlist	*l;

	l = *la;
	while (i > 0)
	{
		l = l->next;
		i--;
	}
	return (l);
}

int	ft_eighthoccur(t_intlist **l)
{
	int			i;
	t_intlist	*ls;

	i = 0;
	ls = *l;
	while (i < 8)
	{
		ls = ls->next;
		i++;
	}
	return (ls->content);
}

t_intlist	*ft_lstlastlast(t_intlist *l)
{
	t_intlist	*t;

	t = l;
	while (t->next->next)
		t = t->next;
	return (t);
}
