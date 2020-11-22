/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:03:36 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/22 18:59:03 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include "minirt.h"

typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}               t_list;

t_list			*ft_lstlast(t_list *lst);
void            ft_lstaddback(t_list **alst, t_list *new);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

#endif