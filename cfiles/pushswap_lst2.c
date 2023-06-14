/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_lst2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:29:08 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/14 13:36:16 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ps_lstsize(t_intlist *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ps_lstclear(t_intlist **lst)
{
	t_intlist	*i;
	t_intlist	*j;

	if (!lst || !*lst)
		return ;
	i = *lst;
	while (ps_lstsize(i) > 1)
	{
		j = i->next;
		i->next = j->next;
		ps_lstdelone(j);
	}
	ps_lstdelone(i);
	*lst = 0;
}

void	ps_lstdelone(t_intlist *lst)
{
	if (!lst)
		return ;
	free(lst);
}

int	ps_free(t_intlist **la, char **argv, int j)
{
	int	i;

	i = 0;
	if (j == 2)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	ps_lstclear(la);
	return (0);
}
