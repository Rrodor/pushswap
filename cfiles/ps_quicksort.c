/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:12:52 by romeo             #+#    #+#             */
/*   Updated: 2023/06/08 19:18:53 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ps_quicksort(t_intlist **la, t_intlist **lb, int *tab, int size)
{
	t_point	s;
	int		med;

	s.size2 = size / 2;
	if (size % 2 == 0)
		s.size2--;
	s.size1 = size / 2;
	med = ps_getmed(la, tab, size);
	ps_quicksortp1(la, lb, med, size);
	if (s.size1 == 5)
		bruteforce5(la, lb);
	if (s.size1 == 4)
		bruteforce4(la, lb);
	if (s.size1 == 3)
		bruteforce3v2(la, lb);
	else if (s.size1 == 2)
		bruteforce2(la, lb);
	else
		ps_quicksort(la, lb, tab, s.size1);
	if (ft_inorder2(la, s.size1, size - 1) == 0)
		return ;
	if (s.size2 <= 5)
		ps_quicksortp2(la, lb, s.size1, s.size2);
	else
		ps_quicksortp3(la, lb, s, tab);
}

void	ps_quicksortp2(t_intlist **la, t_intlist **lb, int s1, int s2)
{
	int	j;

	j = 0;
	while (s1 > 0)
	{
		ps_rotate(la, lb, 'a');
		s1--;
		j++;
	}
	ps_rotate(la, lb, 'a');
	j++;
	if (s2 == 5)
		bruteforce5(la, lb);
	if (s2 == 4)
		bruteforce4(la, lb);
	if (s2 == 3)
		bruteforce3v2(la, lb);
	if (s2 == 2)
		bruteforce2(la, lb);
	while (j > 0)
	{
		ps_revrotate(la, lb, 'a');
		j--;
	}
}

void	ps_quicksortp3(t_intlist **la, t_intlist **lb, t_point s, int *tab)
{
	int	j;

	j = 0;
	while (s.size1 > 0)
	{
		ps_rotate(la, lb, 'a');
		s.size1--;
		j++;
	}
	ps_rotate(la, lb, 'a');
	j++;
	ps_quicksort(la, lb, tab, s.size2);
	while (j > 0)
	{
		ps_revrotate(la, lb, 'a');
		j--;
	}
}

void	ps_quicksortp1(t_intlist **la, t_intlist **lb, int med, int size)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (k + j < size)
	{
		if ((*la)->content < med)
			k++;
		if ((*la)->content < med)
			ps_rotate(la, lb, 'a');
		else
		{
			ps_push(la, lb, 'b');
			j++;
		}
	}
	while (j-- > 0)
	{
		if ((*lb)->content == med && ps_lstsize(*lb) > 1 && j > 0)
			ps_swap(*la, *lb, 'b');
		ps_push(la, lb, 'a');
	}
	while (k-- > 0)
		ps_revrotate(la, lb, 'a');
}

int	ps_getmed(t_intlist **la, int *tab, int size)
{
	int			i;
	int			j;
	t_intlist	*t;

	i = (*la)->content;
	j = 1;
	t = (*la)->next;
	while (j < size)
	{
		if (t->content < i)
			i = t->content;
		j++;
		t = t->next;
	}
	j = 0;
	while (i != tab[j])
		j++;
	if (size % 2 == 0)
		i = size / 2;
	else
		i = size / 2;
	return (tab[j + i]);
}
