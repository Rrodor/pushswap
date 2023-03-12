/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_mvm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:54:11 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/10 19:42:59 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(int *lsta, int *lstb, char c)
{
	int	t;

	if (c == 'a' || c == 's')
	{
		t = ltsa[0];
		lsta[0] = lsta[1];
		lsta[1] = t;
		if (c == 'a')
			ft_printf("sa\n");
	}
	if (c == 'b' || c == 's')
	{
		t = lstb[0];
		lstb[0] = lstb[1];
		lstb[1] = t;
		if (c == 'b')
			ft_printf("sb\n");
	}
	if (c == 's')
		ft_printf("ss\n");
}

void	ft_push(int *lsta, int *lstb, char c)
{
	int	t;

	if (c == 's')
	{
		t = ltsa[0];
		lsta[0] = lstb[0];
		lstb[0] = t;
	}
}
