/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:52:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/23 19:33:57 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	ft_printlst(int n)
{
	ft_printf("%d\n", n);
}

void	ft_ifswap(t_list **la, t_list **lb)
{
 if ((*la) && (*la)->next && ((*la)->content > ((*la)->next)->content))
	{
	 if ((*lb) && (*lb)->next && ((*lb)->content < ((*lb)->next)->content))
			ps_swap(*la, *lb, 's');
		else
			ps_swap(*la, *lb, 'a');
	}
	else if ((*lb) && (*lb)->next && ((*lb)->content < ((*lb)->next)->content))
		ps_swap(*la, *lb, 'b');
	/*if ((*la) && (*la)->next && (ft_lstlastlast(*la)->content > (ft_lstlast(*la)->content)))
	{
	 if ((*lb) && (*lb)->next && (ft_lstlastlast(*lb)->content > (ft_lstlast(*lb)->content)))
		{
			ps_revrotate(la, lb, 'r');
			ps_revrotate(la, lb, 'r');
			ps_swap(*la, *lb, 's');
			ps_rotate(la, lb, 'r');
			ps_rotate(la, lb, 'r');
		}
		else 
		{
			ps_revrotate(la, lb, 'a');
			ps_revrotate(la, lb, 'a');
			ps_swap(*la, *lb, 'a');
			ps_rotate(la, lb, 'a');
			ps_rotate(la, lb, 'a');
		}
	}
	else if ((*lb) && (*lb)->next && (ft_lstlastlast(*lb)->content > (ft_lstlast(*lb)->content)))
	{
		ps_revrotate(la, lb, 'a');
		ps_revrotate(la, lb, 'a');
		ps_swap(*la, *lb, 'a');
		ps_rotate(la, lb, 'a');
		ps_rotate(la, lb, 'a');
	}*/
}

void	ft_pushswap(t_list **la, t_list **lb)
{
	int		t;
	int		i;
	int		l;

	l = ft_lstsize(*la);
	while (checkolst(la, &t) != -1)
	{
		i = checkolst(la, &t);
		ft_printf("\nINF\n");
		while ((*la)->content != t)
		{
			if ((*la)->content < t)
				ps_push(la, lb, 'b');
			else
				ps_rotate(la, lb, 'a');
		}
		/*ps_rotate(la, lb, 'a');
		while ((*la)->content != t)
		{
			if ((*la)->content > t)	
				ps_push(la, lb, 'b');
			else
					ps_rotate(la, lb, 'a');
			}*/
		while (*lb && (*lb)->content > (*la)->content)
				ps_push(la, lb, 'a');
	}
	while (*lb)
		ps_push(la, lb, 'a');
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
	ft_printf("\nA\n");
	ft_lstiter(*la, (ft_printlst));
	ft_printf ("\nB\n");
	ft_lstiter(*lb, (ft_printlst));
	return (0);
}