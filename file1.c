/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:52:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/10 18:44:52 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	pushswap(int *lst)
{
	ft_swap (lst, 'b');
}

int	main(int argc, char **argv)
{
	int		i;
	int		*lst;

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
	i = 0;
	lst = malloc ((argc - 1) * sizeof(int));
	while (i < argc - 1)
	{
		lst[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (argc != 2)
		pushswap(lst);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", lst[i]);
		i++;
	}
	return (0);
}
