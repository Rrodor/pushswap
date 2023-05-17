/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:37:11 by romeo             #+#    #+#             */
/*   Updated: 2023/05/16 18:48:10 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bruteforce3(t_intlist **la, t_intlist **lb)
{
	int	a;
	int	b;
	int	c;

	a = (*la)->content;
	b = (*la)->next->content;
	c = (*la)->next->next->content;
	if (a > b && a < c) //213
		ps_swap(*la, *lb, 'a');
	else if (a < b && a < c && c < b) //132
	{
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
	}
	else if (a < b && c < a) //231
		ps_revrotate(la, lb, 'a');
	else if (a > b && b > c)
	{
		ps_rotate(la, lb, 'a');
		ps_swap(*la, *lb, 'a');
	}
	else if (a > c && b < c)
		ps_rotate(la, lb, 'a');
}

void	bruteforce3v2(t_intlist **la, t_intlist **lb)
{
	int	a;
	int	b;
	int	c;

	a = (*la)->content;
	b = (*la)->next->content;
	c = (*la)->next->next->content;
	if (a > b && a < c) //213
		ps_swap(*la, *lb, 'a');
	else if (a < b && a < c && c < b) //132
	{
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
	}
	else if (a < b && c < a) //231
	{
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
		ps_swap(*la, *lb, 'a');
	}
	else if (a > b && b > c) //321
	{
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
		ps_swap(*la, *lb, 'a');
	}
	else if (a > c && b < c) //312
	{
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
	}
}

void	bruteforce2(t_intlist **la, t_intlist **lb)
{
	if ((*la)->content > (*la)->next->content)
		ps_swap(*la, *lb, 'a');
}