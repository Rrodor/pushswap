/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:52:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/19 01:06:18 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	ft_printlst(int n)
{
	ft_printf("%d\n", n);
}

void	ft_pushswap(t_intlist **la, t_intlist **lb)
{
	int		*tab;
	int		size;
	int		i;
	int		part;

	i = 0;
	tab = ft_reftab(la, &size);
	//ft_printf("size = %d\n", size);
	while (i < size)
	{
		//ft_printf("%d\n", tab[i]);
		i++;
	}
	//ps_push(la, lb, 'b');
	part = size / SIZEPART;
	if (size % SIZEPART)
		part++;
	ft_divide(la, lb, part, tab, size, 2);
	//ft_divide(lb, la, part, tab, size, 2);
	//ft_tri(la, lb, tab, size);
	//ft_printf("%d", part);
}

void	ft_tri(t_intlist **la, t_intlist **lb, int *tab, int size)
{
	int	p;
	int	i;
	int	j;

	j = 0;
	p = (*lb)->content;
	ps_push(la, lb, 'a');
	while (j < SIZEPART - 1)
	{
		if ((*lb)->content < p)
			ps_push(la, lb, 'a');
		else
		{
			i = 0;
			/*while ((*la)->content != p)
			{
				ps_rotate(la, lb, 'a');
				i++;
			}*/
			ps_push(la, lb, 'a');
			//while (i >= 0)
			//{
				ps_rotate(la, lb, 'a');
			//	i--;
			//}
		}
		j++;
	}
	
		
}


void **ft_divide(t_intlist **la, t_intlist **lb, int part, int *tab, int size, int test)
{
	//t_intlist	**lb;
	int			i;
	int			j;
	int			k;
	int			min;
	int			max;

	i = 0;
	while (i < part - 1 && ps_lstsize(*la) > SIZEPART / test)
	{
		j = 0;
		while (ps_lstsize(*lb) < ((SIZEPART / test) * (i + 1)))
		{
			//ft_printf("%d", ps_lstsize(*la));
			//ft_printf("\n%d\n\n", tab[i * 10]);
			k = 0;
			min = tab[i * (SIZEPART / test)];
			while ((i * (SIZEPART / test)) + k < size - 1 && k < SIZEPART / test)
				k++;
			max = tab[i * (SIZEPART / test) + k];
			//ft_printf ("%d %d %d\n", (*la)->content, min, max);
			if ((*la)->content < max)
			{
				ps_push(la, lb, 'b');
				//ft_ifswap(la, lb);
			}
			else if (ft_shortpath(la, tab, size, i) == 1)
			//else
				ps_rotate(la, lb, 'a');
			else
				ps_revrotate(la, lb, 'a');
			j++;
		}
		i++;
		//ft_printf("%d\n", i);
	}
	while ((*la) != NULL)
		ps_push(la, lb, 'b');
}

void	ft_ifswap(t_intlist **la,t_intlist **lb)
{
	static int j = 1;
	int	i;
	
	i = 0;
	j *= -1;
	if (j > 0)
		return ;
	if (ps_lstsize(*lb) > 1 && (*lb)->content < (*lb)->next->content)
		i++;
	if (ps_lstsize(*la) > 1 && (*la)->content > (*la)->next->content)
		i += 2;
	
	if (i == 3)
		ps_swap(*la, *lb, 's');
	if (i == 2)
		ps_swap(*la, *lb, 'a');
	if (i == 1)
		ps_swap(*la, *lb, 'b');
}

int	ft_shortpath(t_intlist **la, int *tab, int size, int part)
{
	t_intlist	*l;
	int			i;
	int			j;
	int			min;
	int			max;

	l = *la;
	i = 0;
	j = 0;
	min = tab[part * SIZEPART];
	while ((part * SIZEPART) + i < size - 1 && i < SIZEPART)
		i++;
	max = tab[part * SIZEPART + i];
	//ft_printf("min=%d max=%d\n", (*la)->content, min, max);
	i = 0;
	while (l -> next != NULL && (l->content < min || l->content >= max))
	{
		l = l->next;
		i++;
	}
	while (l != NULL)
	{
		j++;
		if (l->content < max)
			j = 0;
		l = l->next;
	}
	//ft_printf ("i = %d j = %d\n", i, j);
	//ft_lstiter(*la, (ft_printlst));
	if (i < j)
		return (1);
	else
		return (0);
}

int	*ft_reftab(t_intlist **la, int *size)
{
	int	*tab;
	t_intlist *l;
	int i;
	int j;
	int	j2;
	int k;
	
	i = 0;
	j = (*la)->content;
	*size = ps_lstsize(*la);
	tab = (int *) malloc (*size * sizeof(int));
	if (!tab)
		return (NULL);
	l = *la;
	k = 0;
	while (k < *size)
	{
		if (j > l->content)
			j = l->content;
		k++;
		l = l->next;
	}
	tab[i] = j;
	i++;
	while (i < *size)
	{
		k = 0;
		j2 = j;
		j = __INT_MAX__;
		l =  *la;
		while (k < *size)
		{
			//ft_printf("j = %d, j2=%d, l = %d\n", j, j2, l->content);
			if (j > l->content && l->content > j2)
				j = l->content;
			k++;
			l = l->next;
		}
		tab[i] = j;
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	int		i;
	int		t;
	t_intlist	*lsta;
	t_intlist	*lstb;
	t_intlist	**la;
	t_intlist	**lb;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!testatoi(argv[i]))
		{
			ft_printf("Erreur");
			return (0);
		}
		i++;
	}
	i = 1;
	lsta = NULL;
	lstb = NULL;
	while (i < argc)
	{
		t = ft_atoi(argv[i]);
		if (!(lsta))
			ps_lstadd_back(&lsta, ps_lstnew(t));
		else
			ps_lstadd_back(&lsta, ps_lstnew(t));
		i++;
	}
	la = &lsta;
	lb = &lstb;
	ft_pushswap(la, lb);
	/*ft_printf("\nA\n");
	ps_lstiter(*la, (ft_printlst));
	ft_printf ("\nB\n");
	ps_lstiter(*lb, (ft_printlst));*/
	return (0);
}
