/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:02 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/13 18:31:28 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	*ft_reftab(t_intlist **la, int *size)
{
	int			*tab;
	t_intlist	*l;
	int			i;
	int			j;
	int			k;

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
	tab[i++] = j;
	while (i < *size)
		tab[i++] = ft_reftab2(la, &j, size);
	return (tab);
}

int	ft_reftab2(t_intlist **la, int *j, int *size)
{
	int			j2;
	int			k;
	t_intlist	*l;

	k = 0;
	j2 = *j;
	*j = __INT_MAX__;
	l = *la;
	while (k < *size)
	{
		if (*j > l->content && l->content > j2)
			*j = l->content;
		k++;
		l = l->next;
	}
	return (*j);
}

int	ps_islstvalid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_printf("too few argument, format is ./push_swap [list]\n");
		return (0);
	}
	if (argc == 2)
		return (0);
	while (i < argc)
	{
		if (!testatoi(argv[i]))
		{
			ft_printf("Error : \"%s\" is not a valid number\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ps_testdoublon(t_intlist **la)
{
	t_intlist	*l1;
	t_intlist	*l2;

	l1 = *la;
	while (ps_lstsize(l1) > 1)
	{
		l2 = l1->next;
		if (l2 == NULL)
			return (0);
		while (ps_lstsize(l2) >= 1)
		{
			if (l2->content == l1->content)
			{
				ft_printf("Error : %d is present", l1->content);
				ft_printf(" more than one time\n");
				return (0);
			}
			l2 = l2->next;
		}
		l1 = l1->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_intlist	*lsta;
	t_intlist	*lstb;

	if (argc == 2)
		argv = ps_split(argv[1], ' ', &argc);
	if (ps_islstvalid(argc, argv) == 0)
		return (0);
	i = 0;
	lsta = NULL;
	lstb = NULL;
	while (++i < argc)
		ps_lstadd_back(&lsta, ps_lstnew(ft_atoi(argv[i])));
	if (ps_testdoublon(&lsta))
	{
		if (argc == 3)
			bruteforce2(&lsta, &lstb);
		if (argc == 6)
			bruteforce5short(&lsta, &lstb);
		else
			ft_pushswap(&lsta, &lstb);
	}
	ps_lstclear(&lsta);
	return (0);
}
