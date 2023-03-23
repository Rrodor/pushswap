/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:18:15 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/23 19:04:32 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft.h"

int		testatoi(char *str);
void	ft_printlst(int n);
void	ps_swap(t_list *lsta, t_list *lstb, char c);
void	ps_push(t_list **la, t_list **lb, char c);
void	ps_rotate(t_list **la, t_list **lb, char c);
void	ps_revrotate(t_list **la, t_list **lb, char c);
void	ft_pushswap(t_list **la, t_list **lb);
int		checkolst(t_list **la, int *d);
void	ft_ifswap(t_list **la, t_list **lb);

#endif
