/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce2p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:40:26 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/10 18:52:16 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bruteforce5short(t_intlist **la, t_intlist **lb)
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
	else
		bruteforce5shortp2(la, lb, j);
}

void	bruteforce5shortp2(t_intlist **la, t_intlist **lb, int min)
{
	int			i;
	int			j;

	i = 5;
	j = 0;
	while (i-- > 0 && j < 2)
	{
		if ((*la)->content <= min)
			ps_push(la, lb, 'b');
		if ((*la)->content <= min)
			j++;
		if ((*la)->content > min)
			ps_rotate(la, lb, 'a');
	}
	bruteforce3(la, lb);
	if ((*lb)->content < (*lb)->next->content)
		ps_swap(*la, *lb, 'b');
	ps_push(la, lb, 'a');
	ps_push(la, lb, 'a');
}
