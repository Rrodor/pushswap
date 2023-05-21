/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:37:11 by romeo             #+#    #+#             */
/*   Updated: 2023/05/21 17:10:23 by romeo            ###   ########.fr       */
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
	if (bf5_last(la) == 2)
		bruteforce3v2(la, lb);
	if (bf5_last(la) == 1)
		bruteforce4(la, lb);
	else
		bruteforce5p2(la, lb, j);
}

void	bruteforce5p2(t_intlist **la, t_intlist **lb, int min)
{
	int			i;
	int			j;
	int			k;

	i = 5;
	j = 0;
	k = 0;
	while (i > 0 && j < 2)
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
	while (k > 0)
	{
		ps_revrotate(la, lb, 'a');
		k--;
	}
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
		//ft_printf("%d", i);
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
	//ft_printf("test");
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
	while (k > 0)
	{
		ps_revrotate(la, lb, 'a');
		k--;
	}
	bruteforce3v2(la, lb);
	ps_push(la, lb, 'a');
}