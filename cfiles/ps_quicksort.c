/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:12:52 by romeo             #+#    #+#             */
/*   Updated: 2023/05/12 18:55:14 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ps_quicksort(t_intlist **la, t_intlist **lb, int part, int *tab)
{
	int	s1;
	int	s2;
	int	med;
	int	i;
	int	j;
	int	k;
	
	i = 0;
	if (SIZEPART % 2 == 0)
		s1 = SIZEPART / 2 - 1;
	else
		s1 = SIZEPART / 2;
	s2 = SIZEPART / 2;
	med = tab[i * SIZEPART + SIZEPART / 2];
	//ft_printf("med = %d, v = %d\n", med, (*la)->content);
	j = 0;
	k = 0;
	while (i < SIZEPART)
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
		if ((*lb)->content == med && ps_lstsize(*lb) > 1)
			ps_swap(*la, *lb, 'b');
		ps_push(la, lb, 'a');
		j--;
	}
	while (k > 0)
	{
		ps_revrotate(la, lb, 'a');
		k--;
	}
}