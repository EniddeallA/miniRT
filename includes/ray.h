/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:38:22 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/16 14:26:17 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "minirt.h"
# include "scene.h"

typedef struct  s_ray
{
    t_vector    origin;
    t_vector    direction;
}               t_ray;

t_ray			create_ray(t_vector origin, t_vector direction);
t_ray           ray_to_pixel(int x, int y, t_scene *s);
t_camera        pick_camera(t_scene *s);
t_vector        get_direction(int x, int y, t_scene *s, t_camera cam);

#endif