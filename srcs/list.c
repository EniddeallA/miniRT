/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:34:32 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/22 18:41:05 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_list  *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst= lst->next;
    return (lst);
}

void    ft_lstaddback(t_list **alst, t_list *new)
{
    t_list *temp;

    if (!*alst)
        *alst = new;
    else if (alst && new && *alst)
	{
		temp = ft_lstlast(*alst);
		temp->next = new;
	}
}

t_list  *ft_lstnew(void *content)
{
    t_list *lst;

    if (!(lst = malloc(sizeof(t_list))))
        return (0);
    lst->content = content;
    lst->next = NULL;
    return (lst);
}

int     ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}