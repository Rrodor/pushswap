/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:58:17 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/12 18:35:51 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*res;
	t_list	*x;

	res = 0;
	x = 0;
	if (!lst)
		return (NULL);
	while (lst)
	{
		x = ft_lstnew(((f(lst->content))));
		if (!(x->content))
		{
			ft_lstdelone(x, del);
			return (NULL);
		}
		if (!res)
			res = x;
		else
			ft_lstadd_back(&res, x);
		lst = lst->next;
	}
	return (res);
}
