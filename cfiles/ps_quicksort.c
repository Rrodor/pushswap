/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:12:52 by romeo             #+#    #+#             */
/*   Updated: 2023/05/21 16:38:00 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ps_quicksort(t_intlist **la, t_intlist **lb, int *tab, int size)
{
	int	s1;
	int	s2;
	int	med;
	int	i;
	int	j;
	int	k;
	
	i = 0;
	if (size % 2 == 0)
		s2 = size / 2 - 1;
	else
		s2 = size / 2;
	s1 = size / 2;
	med = ps_getmed(la, tab, size);
	//ft_printf("med = %d, v = %d\n", med, (*la)->content);
	j = 0;
	k = 0;
	while (i < size)
	{
		//ft_printf("med = %d, v = %d\n", med, (*la)->content);
		if ((*la)->content < med)
		{
			ps_rotate(la, lb, 'a');
			k++;
		}
		else
		{
			ps_push(la, lb, 'b');
			//if ((*lb)->next && (*lb)->next->content == med)
			//	ps_swap(*la, *lb, 'b');
			j++;
		}
		i++;
	}
	while (j > 0)
	{
		if ((*lb)->content == med && ps_lstsize(*lb) > 1 && j > 1)
			ps_swap(*la, *lb, 'b');
		ps_push(la, lb, 'a');
		j--;
	}
	while (k > 0)
	{
		ps_revrotate(la, lb, 'a');
		k--;
	}
	//ft_printf("s1=%d s2=%d", s1, s2);
	if (s1 == 5)
		bruteforce5(la, lb);
	if (s1 == 4)
		bruteforce4(la, lb);
	if (s1 == 3)
		bruteforce3v2(la, lb);
	else if (s1 == 2)
		bruteforce2(la, lb);
	else 
		ps_quicksort(la, lb, tab, s1);
	//ft_printf("s1=%d s2=%d", s1, s2);
	//ft_printf("\nAA\n");
	//ps_lstiter(*la, (ft_printlst));
	//ft_printf ("\nB\n");
	//ps_lstiter(*lb, (ft_printlst));
	//ft_printf("%d %d\n", s1, size);
	if (ft_inorder2(la, s1, size - 1) == 0)
		return ;
	if (s2 <= 5)
	{
		j = 0;
		while (s1 > 0)
		{
			ps_rotate(la, lb, 'a');
			s1--;
			j++;
		}
		ps_rotate(la, lb, 'a');
		j++;
		//ft_printf("\nAAAAA\n");
		//ps_lstiter(*la, (ft_printlst));
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
	else
	{
		j = 0;
		while (s1 > 0)
		{
			ps_rotate(la, lb, 'a');
			s1--;
			j++;
		}
		ps_rotate(la, lb, 'a');
		j++;
		ps_quicksort(la, lb, tab, s2);
		while (j > 0)
		{
			ps_revrotate(la, lb, 'a');
			j--;
		}
	}
}

int	ps_getmed(t_intlist **la, int *tab, int size)
{
	int	i;
	int	j;
	t_intlist *t;
	
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
	//ft_printf ("test=%d\n", tab[j]); 
	return (tab[j + i]);
}
