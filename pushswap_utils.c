/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:46:18 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/23 18:49:12 by rrodor           ###   ########.fr       */
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

int checkolst(t_list **la, int *d)
{
    t_list  *t;
    int     i;

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

t_list *ft_lstlastlast(t_list *l)
{
    t_list *t;

    t = l;
    while (t->next->next)
        t = t->next;
    return (t);
}

