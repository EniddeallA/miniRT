/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:54:52 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/30 15:10:37 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		get_color(t_scene *s, t_ray r)
{
	double		t_min;
	t_object	*closest_object;
	t_fcolor	color;
	t_fcolor	ambient;

	if (intersert_with_all(s->objects, r, &closest_object, &t_min))
	{
		ambient = fcolor_coeff(s->ambient, s->ambient_ratio);
		color = fcolor_add(fcolor_mult(closest_object->color, ambient),
								shade(s, r, closest_object, t_min));
		return (fcolor_to_int(color));
	}
	else
		return (0);
}

void	send_rays(t_options *opt, int save)
{
	int		x;
	int		y;
	int		color;
	t_pixel	**buffer;

	y = 0;
	buffer = create_buffer(opt->scene->height, opt->scene->width);
	while (y < opt->scene->height)
	{
		x = 0;
		while (x < opt->scene->width)
		{
			color = get_color(opt->scene,
						ray_to_pixel(x, y, opt->scene));
			if (save)
				buffer[y][x] = pix_from_int(color);
			else
				opt->image.addr[y * opt->scene->width + x] = color;
			x++;
		}
		y++;
	}
	if (save)
		write_bmp("output.bmp", opt->scene->width, opt->scene->height, buffer);
	free_buffer(buffer, opt->scene->height);
}

void	render(int camera_number, t_options *options, int save)
{
	int	cameras_available;

	cameras_available = ft_lstsize(options->scene->cameras);
	options->scene->selected_camera = camera_number % cameras_available;
	send_rays(options, save);
	if (!save)
		mlx_put_image_to_window(options->mlx, options->window,
									options->image.img, 0, 0);
}

int		rerender(int key, t_options *options)
{
	if (key == 45)
		options->camera_number += 1;
	else if (key == 35)
		options->camera_number -= 1;
	else if (key == 53)
		exit(0);
	render(options->camera_number, options, 0);
	return (0);
}

int		fexit(int key, t_options *options)
{
	mlx_destroy_window(options->mlx, options->window);
	exit(0);
}
