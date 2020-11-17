/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:50:23 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/17 19:22:15 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		argbconverter(int a, int r, int g, int b)
{
	return(a << 24 | r << 16 | g << 8 | b);
}

void render(void *mlx, void *window, t_scene s, t_object o)
{
    
}

void raytrace(t_scene s, t_object o)
{
    void *mlx;
    void *window;
    
    mlx = mlx_init();
    window = mlx_new_window(mlx, s.res.x, s.res.y, "miniRT");
    render(mlx, window, s, o);
    mlx_loop(mlx);
}