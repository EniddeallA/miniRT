/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:50:23 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/15 17:58:49 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		argbconverter(int a, int r, int g, int b)
{
	return(a << 24 | r << 16 | g << 8 | b);
}

void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// void startRt(void *mlx, void *window, t_scene s, t_object o)
// {
    
// }

void raytrace(t_scene s, t_object o)
{
    void *mlx;
    void *window;
    t_img image;
    
    mlx = mlx_init();
    window = mlx_new_window(mlx, s.res.x, s.res.y, "miniRT");
    
    //startRt(mlx, window, s, o);
    image.img = mlx_new_image(mlx, s.res.x, s.res.y);
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    my_mlx_pixel_put(&image, 5,5, 0x00FF0000);
    mlx_put_image_to_window(mlx, window, image.img, 0, 0);
    mlx_loop(mlx);
}