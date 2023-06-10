/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:18:46 by romeo             #+#    #+#             */
/*   Updated: 2023/05/25 16:27:22 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bruteforce4(t_intlist **la, t_intlist **lb)
{
	t_intlist	*t;
	int			i;
	int			j;

	t = *la;
	j = t->content;
	i = 3;
	t = t->next;
	while (i > 0)
	{
		if (j > t->content)
			j = t->content;
		t = t->next;
		i--;
	}
	bruteforce4p2(la, lb, j);
}

void	bruteforce4p2(t_intlist **la, t_intlist **lb, int min)
{
	int			i;
	int			j;
	int			k;

	i = 4;
	j = 0;
	k = 0;
	while (i > 0 && j < 1)
	{
		if ((*la)->content <= min)
		{
			ps_push(la, lb, 'b');
			j++;
		}
		else
		{
			ps_rotate(la, lb, 'a');
			k++;
		}
		i--;
	}
	while (k-- > 0)
		ps_revrotate(la, lb, 'a');
	bruteforce3v2(la, lb);
	ps_push(la, lb, 'a');
}
