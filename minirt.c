/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:50:23 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/19 23:47:56 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		argbconverter(int a, int r, int g, int b)
{
	return(a << 24 | r << 16 | g << 8 | b);
}

void render(t_options option, int save)
{
    
}

void raytrace(int fd, int save)
{
    t_options option;

    option.scene = readRtFile(fd);
    if (save == 1)
    {
        render(option, save);
        return ;
    }
    option.id = mlx_init();
    option.window = mlx_new_window(option.id, option.scene->res.x, option.scene->res.y, "miniRT");
    option.image.img = mlx_new_image(option.id, option.scene->res.x, option.scene->res.y);
    option.image.addr = mlx_get_data_addr(option.image.img, &option.image.bits_per_pixel, &option.image.line_length, &option.image.line_length);
    render(option, save);
    mlx_loop(option.id);
}