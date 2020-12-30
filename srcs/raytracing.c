/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:11:32 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:26:58 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	intersect(t_ray r, t_object *obj, double *t)
{
	if (obj->type == SPHERE)
		return (intersect_with_sphere(r, *(t_sphere *)obj->ptr, t));
	else if (obj->type == PLANE)
		return (intersect_with_plane(r, *(t_plane *)obj->ptr, t));
	else if (obj->type == TRIANGLE)
		return (intersect_with_triangle(r, *(t_triangle *)obj->ptr, t));
	else if (obj->type == SQUARE)
		return (intersect_with_square(r, *(t_square *)obj->ptr, t));
	else if (obj->type == CYLINDER)
		return (intersect_with_cylinder(r, *(t_cylinder *)obj->ptr, t));
	else
		return (0);
}

int	intersert_with_all(t_list *obj, t_ray r, t_object **closest_object,
						double *t_min)
{
	t_list		*list;
	t_object	*this_obj;
	double		t;

	*closest_object = NULL;
	list = obj;
	*t_min = HUGE_VAL;
	while (list)
	{
		this_obj = list->content;
		if (intersect(r, this_obj, &t))
			if (t < *t_min)
			{
				*closest_object = this_obj;
				*t_min = t;
			}
		list = list->next;
	}
	if (*closest_object)
		return (1);
	return (0);
}
