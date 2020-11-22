/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:39:43 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/22 18:58:56 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include "minirt.h"

typedef struct  s_fcolor
{
    float r;
    float g;
    float b;
}               t_fcolor;

typedef struct  s_icolor
{
    int r;
    int g;
    int b;
}               t_icolor;

int         color_to_int(t_icolor c);
t_icolor    int_to_color(int rgb);


#endif