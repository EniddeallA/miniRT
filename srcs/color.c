/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:46:08 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/22 18:53:04 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int         color_to_int(t_icolor c)
{
	return(c.r << 16 | c.g << 8 | c.b);
}

t_icolor    int_to_color(int rgb)
{
    t_icolor c;

    c.r = rgb >> 16 & 0xFF;
    c.g = rgb >> 8 & 0xFF;
    c.b = rgb & 0xFF;
    return (c);
}