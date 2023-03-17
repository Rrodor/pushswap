/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:52:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/17 20:29:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	testatoi(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_printlst(int n)
{
	ft_printf("%d\n", n);
}

int	checkolst(t_list **la, int *d)
{
	t_list	*t;
	int		i;

	i = 0;
	t = *la;
	while (t->next)
	{
		if (t->content > (t->next)->content)
		{
			*d = (t->next)->content;
			return (i);
		}
		t = t->next;
		i++;
	}
	return (-1);
}

void	ft_pushswap(t_list **la, t_list **lb)
{
	int	t;
	int	i;
	int	l;

	l = ft_lstsize(*la);
	i = checkolst(la, &t);
	ft_printf("i=%d\n", i);
	//ft_printf("Ti=%d v1=%d t=%dT\n", i, (*la)->content, t);
	while (i >= 0)
	{
		if ((*la)->next && ((*la)->content > ((*la)->next)->content))
			ps_swap(*la, *lb, 'a');
		if (i < l/2)
		{
			while (*la && (*la)->content != t)
			{
				//ft_printf("v=%d t=%d\n", (*la)->content, t);
				if (t > (*la)->content)
					ps_push(la, lb, 'b');
				else
					ps_rotate(la, lb, 'a');
			}
			while (*lb != NULL && (*lb)->content > (*la)->content)
				ps_push(la, lb, 'a');
		}
		else
		{
			while (*la && (*la)->content != t)
			{
				//ft_printf("v=%d t=%d\n", (*la)->content, t);
				if (t > (*la)->content)
					ps_push(la, lb, 'b');
				else
					ps_revrotate(la, lb, 'a');
			}
			while (*lb != NULL && (*lb)->content > (*la)->content)
				ps_push(la, lb, 'a');
		}
		i = checkolst(la, &t);
		ft_printf("i=%d\n", i);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		t;
	t_list	*lsta;
	t_list	*lstb;
	t_list	**la;
	t_list	**lb;

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
			ft_lstadd_back(&lsta, ft_lstnew(t));
		else
			ft_lstadd_back(&lsta, ft_lstnew(t));
		i++;
	}
	la = &lsta;
	lb = &lstb;
	ft_pushswap(la, lb);
	return (0);
}
