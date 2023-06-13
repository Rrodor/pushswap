/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:08:22 by rrodor            #+#    #+#             */
/*   Updated: 2023/06/13 18:21:05 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ps_countwrd(const char *s, char c)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			l++;
		while (s[i] != c && s[i])
			i++;
	}
	return (l);
}

int	ps_splitinit(char const *s, char c, int *i, int *j)
{
	int	l;

	l = ps_countwrd(s, c);
	*i = 0;
	*j = 1;
	return (l);
}

char	**ps_split(char const *s, char c, int *argc)
{
	char	**wrd;
	int		l;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	l = ps_splitinit(s, c, &i, &j);
	*argc = l + 1;
	wrd = ft_calloc(l + 2, sizeof(char *));
	wrd[0] = ps_name();
	while (j++ < l + 1)
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + k] != c && s[i + k])
			k++;
		wrd[j - 1] = ft_substr(s, i, k);
		if (!wrd[j - 1])
			return (0);
		i += k;
	}
	return (wrd);
}

char	*ps_name(void)
{
	char	*str;

	str = malloc(sizeof(char) * 12);
	if (!str)
		return (0);
	str[0] = '.';
	str[1] = '/';
	str[2] = 'p';
	str[3] = 'u';
	str[4] = 's';
	str[5] = 'h';
	str[6] = '_';
	str[7] = 's';
	str[8] = 'w';
	str[9] = 'a';
	str[10] = 'p';
	str[11] = 0;
	return (str);
}
