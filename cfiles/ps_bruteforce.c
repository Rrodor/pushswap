/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:37:11 by romeo             #+#    #+#             */
/*   Updated: 2023/05/25 18:58:56 by romeo            ###   ########.fr       */
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
	if (a > b && a < c)
		ps_swap(*la, *lb, 'a');
	else if (a < b && a < c && c < b)
	{
		ps_revrotate(la, lb, 'a');
		ps_swap(*la, *lb, 'a');
	}
	else if (a < b && c < a)
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
	if (a > b && a < c)
		ps_swap(*la, *lb, 'a');
	else if (a < b && a < c && c < b)
	{
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
	}
	else if (a < b && c < a)
	{
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
		ps_swap(*la, *lb, 'a');
	}
	else if ((a > b && b > c) || (a > c && b < c))
		bruteforce3v2p2(la, lb);
}

void	bruteforce3v2p2(t_intlist **la, t_intlist **lb)
{
	int	a;
	int	b;
	int	c;

	a = (*la)->content;
	b = (*la)->next->content;
	c = (*la)->next->next->content;
	if (a > b && b > c)
	{
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'b');
		ps_swap(*la, *lb, 'a');
		ps_push(la, lb, 'a');
		ps_swap(*la, *lb, 'a');
	}
	else if (a > c && b < c)
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
