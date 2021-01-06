/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:52:47 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/06 16:41:10 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_camera	pick_camera(t_scene *s)
{
	t_list	*r;
	int		i;

	i = 0;
	r = s->cameras;
	while (i < s->selected_camera && r)
	{
		r = r->next;
		i++;
	}
	return (*(t_camera *)r->content);
}

t_vector	get_direction(int x, int y, t_scene *s, t_camera cam)
{
	double	fov;
	double	ar;
	double	px;
	double	py;

	fov = tan((double)cam.fov / 2 * M_PI / 180);
	ar = (double)s->width / (double)s->height;
	px = (2 * (x + 0.5) / (double)s->width - 1) * ar * fov;
	py = (1 - 2 * (y + 0.5) / (double)s->height) * fov;
	return (create_v3(px, py, 1));
}

t_ray		create_ray(t_vector origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_ray		ray_to_pixel(int x, int y, t_scene *s)
{
	t_camera	cam;
	t_matrix	c2w;
	t_vector	origin;
	t_vector	direction;

	cam = pick_camera(s);
	c2w = look_at(cam.origin, cam.direction);
	origin = multiply_matrix(c2w, create_v3(0, 0, 0));
	direction = get_direction(x, y, s, cam);
	direction = multiply_matrix(c2w, direction);
	direction = substract(direction, origin);
	normalize_vector(&direction);
	return (create_ray(origin, direction));
}
