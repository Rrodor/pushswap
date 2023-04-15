/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:52:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/15 18:57:15 by rrodor           ###   ########.fr       */
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
	ft_printf("size = %d\n", size);
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
	//ps_push(la, lb, 'b');
	part = size / 10;
	if (size % 10)
		part++;
	ft_divide(la, lb, part, tab, size);
	//ft_printf("%d", part);
}

t_intlist **ft_divide(t_intlist **la, t_intlist **lb, int part, int *tab, int size)
{
	t_intlist	**l;
	//t_intlist	**lb;
	int			i;
	int			j;
	
	i = 0;
	while (i < part)
	{
		l = la;
		j = 0;
		while (j < size && (*l) != NULL)
		{
			//ft_printf("%d", ps_lstsize(*la));
			//ft_printf("\n%d\n\n", tab[i * 10]);
			if ((*l)->content >= tab[i * 10] && (*l)->content < tab[(1 + i) * 10])
				ps_push(la, lb, 'b');
			else
				ps_rotate(la, lb, 'a');
			*l = (*l)->next;
			j++;
		}
		i++;
		ft_printf("%d\n", i);
	}
	return (lb);
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
	ft_printf("\nA\n");
	ps_lstiter(*la, (ft_printlst));
	ft_printf ("\nB\n");
	ps_lstiter(*lb, (ft_printlst));
	return (0);
}
