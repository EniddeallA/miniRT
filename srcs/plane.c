/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:29 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:26:52 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	get_plane_normal(t_vector hit_point, t_plane object)
{
	return (object.normal);
}

int			intersect_with_plane(t_ray r, t_plane plane, double *t)
{
	double		denom;
	t_vector	p0l0;

	denom = dot_product(plane.normal, r.direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = substract(plane.p, r.origin);
		*t = dot_product(p0l0, plane.normal) / denom;
		return (*t >= 0);
	}
	return (0);
}
