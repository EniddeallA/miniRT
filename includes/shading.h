/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:21:06 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/16 12:25:13 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include "vector.h"
# include "list.h"
# include "scene.h"
# include "ray.h"
# include "color.h"
# include "minirt.h"

typedef struct  s_inter
{
    t_vector    hit_point;
	t_vector    hit_normal;
	t_list      *objects;
	t_object    *closest_object;
	t_ray       r;
}               t_inter;

t_fcolor        shade(t_scene *s, t_ray r, t_object *closest_object, double t_min);
t_vector        get_normal(t_vector hit_point, t_object *object);
t_inter         intersection(t_vector hit_point, t_vector hit_normal, 
                        t_object *closest_object, t_ray r);
t_fcolor        diffuse_light(t_light light, t_scene *s, t_inter i);
t_fcolor    	compute_shading(t_light light, double coeff, t_inter i);
t_fcolor		phong_specular_model(t_light light, t_inter i);
double			compute_specular(t_light light, t_inter i);

#endif