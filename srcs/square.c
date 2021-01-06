/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:34 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/06 17:14:51 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	get_square_normal(t_square object)
{
	return (object.normal);
}

int			intersect_with_square(t_ray r, t_square square, double *t)
{
	double		denom;
	t_vector	p0l0;
	t_vector	intersection;

	normalize_vector(&square.normal);
	denom = dot_product(square.normal, r.direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = substract(square.p, r.origin);
		*t = dot_product(p0l0, square.normal) / denom;
		intersection = vector_add(r.origin, vector_multiply(r.direction, *t));
		if (*t >= 0)
		{
			if (fabs(intersection.x - square.p.x) > (square.length / 2))
				return (0);
			if (fabs(intersection.y - square.p.y) > (square.length / 2))
				return (0);
			if (fabs(intersection.z - square.p.z) > (square.length / 2))
				return (0);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
