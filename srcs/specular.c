/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:12:17 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:27:02 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

double		compute_specular(t_light light, t_inter i)
{
	t_vector	light_ray;
	t_vector	reflectance_vector;
	t_vector	back_view_ray;
	double		result;

	light_ray = substract(light.origin, i.hit_point);
	normalize_vector(&light_ray);
	reflectance_vector = vector_add(light_ray,
								vector_multiply(vector_multiply(
												i.hit_normal,
												dot_product(light_ray,
													i.hit_normal)), -2));
	back_view_ray = substract(i.hit_point, i.r.origin);
	normalize_vector(&back_view_ray);
	result = fmax(dot_product(reflectance_vector, back_view_ray), 0);
	result = pow(result, 40);
	return (result);
}

t_fcolor	phong_specular_model(t_light light, t_inter i)
{
	t_fcolor	specular;
	t_fcolor	highlight;
	double		metalness;
	double		coeff;

	metalness = 0.1;
	highlight.r = 1;
	highlight.g = 1;
	highlight.b = 1;
	highlight = fcolor_coeff(highlight, (1 - metalness));
	specular = fcolor_add(
					fcolor_coeff(i.closest_object->color, metalness),
					highlight);
	coeff = compute_specular(light, i);
	return (fcolor_coeff(specular, coeff));
}
