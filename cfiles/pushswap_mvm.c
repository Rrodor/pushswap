/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_mvm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:41:07 by rrodor            #+#    #+#             */
/*   Updated: 2023/05/24 21:44:18 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

void	ps_swap(t_intlist *lsta, t_intlist *lstb, char c)
{
	int	t;

	if ((c == 'a' || c == 's') && ps_lstsize(lsta) > 1)
	{
		t = lsta->content;
		lsta->content = (lsta->next)->content;
		(lsta->next)->content = t;
	}
	if ((c == 'b' || c == 's') && ps_lstsize(lstb) > 1)
	{
		t = lstb->content;
		lstb->content = (lstb->next)->content;
		(lstb->next)->content = t;
	}
	ft_printf("s%c\n", c);
}

void	ps_push(t_intlist **la, t_intlist **lb, char c)
{
	t_intlist	*t;

	if (c == 'a' && ps_lstsize(*lb))
	{
		ps_lstadd_front(la, ps_lstnew((*lb)->content));
		t = *lb;
		*lb = (*lb)->next;
		free(t);
	}
	if (c == 'b' && ps_lstsize(*la))
	{
		if (!(*lb))
		{
			(*lb) = ps_lstnew((*la)->content);
		}
		else
			ps_lstadd_front(lb, ps_lstnew((*la)->content));
		t = *la;
		*la = (*la)->next;
		free(t);
	}
	ft_printf("p%c\n", c);
}

void	ps_rotate(t_intlist **la, t_intlist **lb, char c)
{
	t_intlist	*t;

	if (c == 'a' || c == 'r')
	{
		ps_lstadd_back(la, ps_lstnew((*la)->content));
		t = *la;
		*la = t->next;
		free(t);
	}
	if (c == 'b' || c == 'r')
	{
		ps_lstadd_back(lb, ps_lstnew((*lb)->content));
		t = *lb;
		*lb = t->next;
		free(t);
	}
	ft_printf("r%c\n", c);
}

void	ps_revrotate(t_intlist **la, t_intlist **lb, char c)
{
	t_intlist	**t;

	if (c == 'a' || c == 'r')
	{
		ps_lstadd_front(la, ps_lstnew((ps_lstlast(*la))->content));
		t = la;
		while (((*t)->next)->next && (*t)->next)
			t = &((*t)->next);
		free(ps_lstlast(*la));
		(*t)->next = NULL;
	}
	if (c == 'b' || c == 'r')
	{
		ps_lstadd_front(lb, ps_lstnew((ps_lstlast(*lb))->content));
		t = lb;
		while (((*t)->next)->next && (*t)->next)
			t = &((*t)->next);
		free(ps_lstlast(*lb));
		(*t)->next = NULL;
	}
	ft_printf("rr%c\n", c);
}
