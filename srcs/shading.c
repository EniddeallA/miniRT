/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:20:01 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/03 15:37:04 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_fcolor	compute_shading(t_light light, double coeff, t_inter i)
{
	t_fcolor	light_color;
	t_fcolor	object_color;
	t_fcolor	result;

	light_color = fcolor_coeff(light.color, light.intensity);
	object_color = i.closest_object->color;
	result = fcolor_coeff(fcolor_mult(light_color, object_color), coeff);
	if (coeff)
		result = fcolor_add(result, phong_specular_model(light, i));
	return (result);
}

t_fcolor	diffuse_light(t_light light, t_scene *s, t_inter i)
{
	t_ray		lray;
	t_vector	ldirection;
	double		t;
	double		coeff;
	t_object	*closest_object2;

	coeff = 0;
	ldirection = substract(light.origin, i.hit_point);
	normalize_vector(&ldirection);
	lray = create_ray(vector_add(i.hit_point,
						vector_multiply(i.hit_normal, 0.1)), ldirection);
	if (!intersert_with_all(s->objects, lray, &closest_object2, &t) ||
			t > vector_len(substract(light.origin, i.hit_point)))
		coeff = fmax(0, dot_product(i.hit_normal, ldirection));
	return (compute_shading(light, coeff, i));
}

t_inter		intersection(t_vector hit_point, t_vector hit_normal,
								t_object *closest_object, t_ray r)
{
	t_inter	inter;

	inter.hit_point = hit_point;
	inter.hit_normal = hit_normal;
	inter.closest_object = closest_object;
	inter.r = r;
	return (inter);
}

t_vector	get_normal(t_vector hit_point, t_object *object)
{
	if (object->type == SPHERE)
		return (get_sphere_normal(hit_point, *(t_sphere*)object->ptr));
	else if (object->type == PLANE)
		return (get_plane_normal(*(t_plane*)object->ptr));
	else if (object->type == SQUARE)
		return (get_square_normal(*(t_square*)object->ptr));
	else if (object->type == TRIANGLE)
		return (get_triangle_normal(*(t_triangle*)object->ptr));
	else
		return (get_cylinder_normal(hit_point, *(t_cylinder*)object->ptr));
}

t_fcolor	shade(t_scene *s, t_ray r, t_object *closest_object, double t_min)
{
	t_vector	hit_point;
	t_vector	hit_normal;
	t_list		*runner;
	t_fcolor	mult_lights;
	t_fcolor	result;

	result = int_to_fcolor(0);
	hit_point = vector_add(r.origin, vector_multiply(r.direction, t_min));
	hit_normal = get_normal(hit_point, closest_object);
	if (dot_product(r.direction, hit_normal) > 0)
		hit_normal = substract(create_v3(0, 0, 0),
						vector_multiply(hit_normal, 1));
	runner = s->lights;
	while (runner)
	{
		mult_lights = diffuse_light(*(t_light *)(runner->content), s,
						intersection(hit_point, hit_normal, closest_object, r));
		result = fcolor_add(result, mult_lights);
		runner = runner->next;
	}
	return (result);
}
