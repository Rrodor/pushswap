/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_mvm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:41:07 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/20 19:01:19 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

void	ps_swap(t_list *lsta, t_list *lstb, char c)
{
	int	t;

	if ((c == 'a' || c == 's') && ft_lstsize(lsta) > 1)
	{
		t = lsta->content;
		lsta->content = (lsta->next)->content;
		(lsta->next)->content = t;
	}
	if ((c == 'b' || c == 's') && ft_lstsize(lstb) > 1)
	{
		t = lstb->content;
		lstb->content = (lstb->next)->content;
		(lstb->next)->content = t;
	}
	ft_printf("s%c\n", c);
}

void	ps_push(t_list **la, t_list **lb, char c)
{
	t_list	*t;

	if (c == 'a' && ft_lstsize(*lb))
	{
		ft_lstadd_front(la, ft_lstnew((*lb)->content));
		t = *lb;
		*lb = (*lb)->next;
		free(t);
	}
	if (c == 'b' && ft_lstsize(*la))
	{
		if (!(*lb))
		{
			(*lb) = ft_lstnew((*la)->content);
		}
		else
			ft_lstadd_front(lb, ft_lstnew((*la)->content));
		t = *la;
		*la = (*la)->next;
		free(t);
	}
	ft_printf("p%c\n", c);
}

void	ps_rotate(t_list **la, t_list **lb, char c)
{
	t_list	*t;

	if (c == 'a' || c == 'r')
	{
		ft_lstadd_back(la, ft_lstnew((*la)->content));
		t = *la;
		*la = t->next;
		free(t);
	}
	if (c == 'b' || c == 'r')
	{
		ft_lstadd_back(lb, ft_lstnew((*lb)->content));
		t = *lb;
		*lb = t->next;
		free(t);
	}
	ft_printf("r%c\n", c);
}

void	ps_revrotate(t_list **la, t_list **lb, char c)
{
	t_list	**t;

	if (c == 'a' || c == 'r')
	{
		ft_lstadd_front(la, ft_lstnew((ft_lstlast(*la))->content));
		t = la;
		while (((*t)->next)->next && (*t)->next)
		{
			t = &((*t)->next);
			//ft_printf("T%dT\n", (*t)->content);
		}
		free(ft_lstlast(*la));
		(*t)->next = NULL;
	}
	if (c == 'b' || c == 'r')
	{
		ft_lstadd_front(lb, ft_lstnew((ft_lstlast(*lb))->content));
		t = lb;
		while (((*t)->next)->next && (*t)->next)
			t = &((*t)->next);
		free(ft_lstlast(*lb));
		(*t)->next = NULL;
	}
	ft_printf("rr%c\n", c);
}
