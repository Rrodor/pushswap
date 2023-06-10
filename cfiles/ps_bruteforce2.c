/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:47:20 by romeo             #+#    #+#             */
/*   Updated: 2023/06/09 16:31:01 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bruteforce5(t_intlist **la, t_intlist **lb)
{
	t_intlist	*t;
	int			i;
	int			j;
	int			k;

	t = *la;
	j = t->content;
	k = t->next->content;
	if (k > j)
	{
		i = k;
		k = j;
		j = i;
	}
	i = 3;
	t = t->next->next;
	j = bruteforce5bis(i, j, k, t);
	if (bf5_last(la) == 2)
		bruteforce3v2(la, lb);
	if (bf5_last(la) == 1)
		bruteforce4(la, lb);
	else
		bruteforce5p2(la, lb, j);
}

int	bruteforce5bis(int i, int j, int k, t_intlist *t)
{
	while (i > 0)
	{
		if (j > t->content)
		{
			if (k > t->content)
			{
				j = k;
				k = t->content;
			}
			else
				j = t->content;
		}
		t = t->next;
		i--;
	}
	return (j);
}

void	bruteforce5p2(t_intlist **la, t_intlist **lb, int min)
{
	int			i;
	int			j;
	int			k;

	i = 5;
	j = 0;
	k = 0;
	while (i-- > 0 && j < 2)
	{
		if ((*la)->content <= min)
			ps_push(la, lb, 'b');
		if ((*la)->content <= min)
			j++;
		if ((*la)->content > min && k++ >= 0)
			ps_rotate(la, lb, 'a');
	}
	while (k-- > 0)
		ps_revrotate(la, lb, 'a');
	bruteforce3v2(la, lb);
	if ((*lb)->content < (*lb)->next->content)
		ps_swap(*la, *lb, 'b');
	ps_push(la, lb, 'a');
	ps_push(la, lb, 'a');
}

int	bf5_last(t_intlist **la)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = ps_lstelem(la, 0)->content;
	b = ps_lstelem(la, 1)->content;
	c = ps_lstelem(la, 2)->content;
	d = ps_lstelem(la, 3)->content;
	e = ps_lstelem(la, 4)->content;
	if (e > a && e > b && e > c && e > d)
	{
		if (d > a && d > b && d > c)
			return (2);
		return (1);
	}
	return (0);
}
