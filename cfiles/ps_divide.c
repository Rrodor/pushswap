/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:51:43 by romeo             #+#    #+#             */
/*   Updated: 2023/06/09 16:52:48 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_divide1(t_intlist **la, t_intlist **lb, int *tab, t_size size)
{
	int			i;
	int			j;

	i = 0;
	size.tab = tab;
	while (i < (size.stab / size.spart) && ps_lstsize(*la) > size.spart)
	{
		ps_dividebis(la, lb, size, i);
		j = size.spart;
		while (j-- > 0)
			ps_revrotate(la, lb, 'b');
		i += 2;
	}
}

void	ps_dividebis(t_intlist **la, t_intlist **lb, t_size size, int i)
{
	int			min;
	int			max;
	int			max2;

	while (ps_lstsize(*lb) < (size.spart * (i + 2)))
	{
		min = size.tab[i * size.spart];
		max = size.tab[i * size.spart + size.spart - 1];
		max2 = size.tab[(i + 1) * size.spart + size.spart - 1];
		if ((*la)->content <= max && (*la)->content >= min)
			ps_push(la, lb, 'b');
		else if ((*la)->content <= max2 && (*la)->content > max)
		{
			ps_push(la, lb, 'b');
			ps_rotate(la, lb, 'b');
		}
		else
			ps_rotate(la, lb, 'a');
	}
}

void	ps_divide2(t_intlist **la, t_intlist **lb, int *tab, t_size size)
{
	int			i;
	int			j;
	int			max;

	i = 0;
	size.tab = tab;
	while (i < (size.stab / size.spart) - 1 && ps_lstsize(*la) > size.spart)
	{
		ps_dividebis(la, lb, size, i);
		j = size.spart;
		while (j-- > 0)
			ps_revrotate(la, lb, 'b');
		i += 2;
	}
	while (ps_lstsize(*la) > (size.stab % size.spart))
	{
		max = tab[(i) * size.spart + size.spart - 1];
		if ((*la)->content <= max)
			ps_push(la, lb, 'b');
		else
			ps_rotate(la, lb, 'a');
	}
}

void	ps_divide(t_intlist **la, t_intlist **lb, int *tab, t_size size)
{
	if (size.stab % size.spart != 0)
	{
		if ((size.stab / size.spart) % 2 == 0)
			ps_divide1(la, lb, tab, size);
		else
			ps_divide2(la, lb, tab, size);
	}
	else
	{
		if ((size.stab / size.spart) % 2 == 0)
			ps_divide1(la, lb, tab, size);
		else
			ps_divide2(la, lb, tab, size);
	}
}
