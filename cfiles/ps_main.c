/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:02 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/10 16:45:28 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	ft_printlst(int n)
{
	ft_printf("%d\n", n);
}

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

int	main(int argc, char **argv)
{
	int			i;
	t_intlist	*lsta;
	t_intlist	*lstb;

	if (ps_islstvalid(argc, argv) == 0)
		return (0);
	i = 1;
	lsta = NULL;
	lstb = NULL;
	while (i < argc)
	{
		if (!(lsta))
			ps_lstadd_back(&lsta, ps_lstnew(ft_atoi(argv[i])));
		else
			ps_lstadd_back(&lsta, ps_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (argc == 2)
		bruteforce2(&lsta, &lstb);
	ft_pushswap(&lsta, &lstb);
	ps_lstclear(&lsta);
	return (0);
}
