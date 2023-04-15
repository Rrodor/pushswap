/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:46:18 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/15 14:41:57 by rrodor           ###   ########.fr       */
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

int checkolst(t_intlist **la, int *d)
{
    t_intlist  *t;
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
int checkrevolst(t_intlist **la, int *d)
{
    t_intlist  *t;
    int     i;

    if (!la || !*la)
        return (-1);
    i = 0;
    t = *la;
    while (t->next)
    {
        if (t->content < (t->next)->content)
        {
            *d = (t->next)->content;
            //ft_printf("j = %d, t->next->content = %d", j, (t->next)->content);
            return (i);
        }
        t = t->next;
        i++;
    }
    return (-1);
}

t_intlist *ft_lstlastlast(t_intlist *l)
{
    t_intlist *t;

    t = l;
    while (t->next->next)
        t = t->next;
    return (t);
}