/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:51:43 by romeo             #+#    #+#             */
/*   Updated: 2023/05/18 21:39:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void **ps_divide1(t_intlist **la, t_intlist **lb, int *tab, t_size size)
{
	//t_intlist	**lb;
	int			i;
	int			j;
	int			k;
	int			l;
	int			min;
	int			max;
	int			min2;
	int			max2;

	i = 0;
	/*if (ps_lstsize(*la) % SIZEPART == 0)
	{
		if (ps_lstsize(*la) / SIZEPART)
	}*/
	while (i < (size.stab / size.spart) && ps_lstsize(*la) > size.spart)
	{
		j = 0;
		while (ps_lstsize(*lb) < (size.spart * (i + 2)) && j < 1000)
		{
			//ft_printf("%d", ps_lstsize(*la));
			//ft_printf("\n%d\n\n", tab[i * 10]);
			k = 0;
			min = tab[i * size.spart];
			min2 = tab[(i + 1) * size.spart];
			//while ((i * size.spart) + k < size - 1 && k < size.spart)
			//	k++;
			max = tab[i * size.spart + size.spart - 1];
			max2 = tab[(i + 1) * size.spart + size.spart - 1];
			//ft_printf("v=%d min=%d max=%d min2=%d max2=%d\n",(*la)->content, min, max, min2, max2);
			//ft_printf ("%d %d %d\n", (*la)->content, min, max);
			if ((*la)->content <= max && (*la)->content >= min)
			{
				ps_push(la, lb, 'b');
				//ft_ifswap(la, lb);
			}
			else if ((*la)->content <= max2 && (*la)->content >= min2)
			{
				ps_push(la, lb, 'b');
				ps_rotate(la, lb, 'b');
			}
			//else if (ft_shortpath(la, tab, size, i) == 1)
			else
				ps_rotate(la, lb, 'a');
			//else
			//	ps_revrotate(la, lb, 'a');
			j++;
		}
		if (j == 1000)
		{	
			break;
		}
		j = size.spart;
		while (j > 0)
		{
			j--;
			ps_revrotate(la, lb, 'b');
		}
		i += 2;
		//ft_printf("%d\n", i);
	}
	//while ((*la) != NULL)
	//	ps_push(la, lb, 'b');
}

void **ps_divide2(t_intlist **la, t_intlist **lb, int *tab, t_size size)
{
	//t_intlist	**lb;
	int			i;
	int			j;
	int			k;
	int			l;
	int			min;
	int			max;
	int			min2;
	int			max2;

	i = 0;
	while (i < (size.stab / size.spart) - 1 && ps_lstsize(*la) > size.spart)
	{
		j = 0;
		while (ps_lstsize(*lb) < (size.spart * (i + 2)) && j < 1000)
		{
			k = 0;
			min = tab[i * size.spart];
			min2 = tab[(i + 1) * size.spart];
			max = tab[i * size.spart + size.spart - 1];
			max2 = tab[(i + 1) * size.spart + size.spart - 1];
			//ft_printf("v=%d min=%d max=%d min2=%d max2=%d\n",(*la)->content, min, max, min2, max2);
			if ((*la)->content <= max && (*la)->content >= min)
				ps_push(la, lb, 'b');
			else if ((*la)->content <= max2 && (*la)->content >= min2)
			{
				ps_push(la, lb, 'b');
				ps_rotate(la, lb, 'b');
			}
			else
				ps_rotate(la, lb, 'a');
			j++;
		}
		if (j == 1000)
			break;
		j = size.spart;
		while (j > 0)
		{
			j--;
			ps_revrotate(la, lb, 'b');
		}
		i += 2;
	}
	while (ps_lstsize(*la) > (size.stab % size.spart))
	{
		max = tab[(i) * size.spart + size.spart - 1];
		//ft_printf ("%d %d %d ",ps_lstsize(*la), (*la)->content, max);
		if ((*la)->content <= max)
			ps_push(la, lb, 'b');
		else
			ps_rotate(la, lb, 'a');
	}
}

void ps_divide(t_intlist **la, t_intlist **lb, int *tab, t_size size)
{
	if (size.stab % size.spart != 0)
	{
		if ((size.stab / size.spart) % 2 == 0 )
			ps_divide1(la, lb, tab, size);
		else
			ps_divide2(la, lb, tab, size);
	}
	else
	{
		if ((size.stab / size.spart) % 2 == 0 )
			ps_divide1(la, lb, tab, size);
		else
			ps_divide2(la, lb, tab, size);
	}
}

