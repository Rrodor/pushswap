/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:30:58 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/10 18:58:45 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pushswap(t_intlist **la, t_intlist **lb)
{
	int		*tab;
	int		size1;
	int		j;
	t_size	size;

	tab = ft_reftab(la, &size1);
	size.spart = ps_shortsort(la, lb, tab, size1);
	if (size1 < 26)
	{
		free(tab);
		return ;
	}
	size.stab = size1;
	ps_divide(la, lb, tab, size);
	j = 0;
	if (ps_lstsize(*la) == 0)
		while (j++ < size.spart)
			ps_push(la, lb, 'a');
	if (ps_lstsize(*la) != 0)
		ps_quicksort(la, lb, tab, ps_lstsize(*la));
	while (ps_lstsize(*la) < size.stab)
		ft_tri(la, lb, tab, size);
}

int	ps_shortsort(t_intlist **la, t_intlist **lb, int *tab, int size1)
{
	if (ft_inorder2(la, 0, size1 - 1) == 0)
		return (0);
	if (size1 <= 3)
		bruteforce3(la, lb);
	else if (size1 == 4)
		bruteforce4(la, lb);
	else if (size1 == 5)
		bruteforce5(la, lb);
	else if (size1 < 26)
		ps_quicksort(la, lb, tab, ps_lstsize(*la));
	if (size1 < 26)
		return (0);
	if (size1 < 150)
		return (13);
	else
		return (26);
}

void	ft_tri(t_intlist **la, t_intlist **lb, int *tab, t_size size)
{
	int	i;

	i = 0;
	while (i < size.spart)
	{
		ps_push(la, lb, 'a');
		i++;
	}
	ps_quicksort(la, lb, tab, size.spart);
	if (ps_lstsize(*la) == size.stab)
		free(tab);
}

int	ft_inorder(t_intlist **la, int *p)
{
	t_intlist	*l;
	int			i;

	i = ps_lstsize(*la);
	if (i < 2)
		return (0);
	l = ps_lstelem(la, i - 2);
	while (l->content != (*la)->content)
	{
		if (l->content > l->next->content)
		{
			*p = l->next->content;
			return (i + 1);
		}
		l = ps_lstelem(la, i - 2);
		i--;
	}
	return (0);
}
