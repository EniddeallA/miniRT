/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:34 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/06 18:32:40 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	get_square_normal(t_square object)
{
	return (object.normal);
}

// int			intersect_with_square(t_ray r, t_square square, double *t)
// {
// 	double		denom;
// 	t_vector	p0l0;
// 	t_vector	intersection;
// 	double		t_min;

// 	normalize_vector(&square.normal);
// 	denom = dot_product(square.normal, r.direction);
// 	if (fabs(denom) > 1e-6)
// 	{
// 		// p0l0 = substract(square.p, r.origin);
// 		// *t = dot_product(p0l0, square.normal) / denom;
// 		// intersection = vector_add(r.origin, vector_multiply(r.direction, *t));
// 		// if (*t >= 0)
// 		// {
// 		// 	if (fabs(intersection.x - square.p.x) > (square.length / 2))
// 		// 		return (0);
// 		// 	if (fabs(intersection.y - square.p.y) > (square.length / 2))
// 		// 		return (0);
// 		// 	if (fabs(intersection.z - square.p.z) > (square.length / 2))
// 		// 		return (0);
// 		// 	return (1);
// 		// }
// 		// else
// 		// 	return (0);
// 		t_vector arbitray = create_v3(0, 1, 0);
// 		normalize_vector(&arbitray);
// 		t_vector u = cross_product(arbitray, square.normal);
// 		t_vector v = cross_product(r.direction, u);
// 		p0l0 = substract(square.p, r.origin);
// 		t_min = dot_product(p0l0, square.normal);
// 		intersection = vector_add(r.origin, vector_multiply(r.direction, t_min));
// 		intersection = substract(intersection, square.p);
// 		double proj1 = dot_product(u, intersection);
// 		double proj2 = dot_product(v, intersection);
// 		if ((proj1 <= square.length / 2 && proj1 >= -(square.length / 2)) &&
// 			(proj2 <= square.length / 2 && proj2 >= -(square.length / 2)))
// 		{
// 			*t = t_min;
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

int         intersect_with_square(t_ray r, t_square square, double *t)
{
    double      denom;
    t_vector    p0l0;
    t_vector    intersection;
    double      t_min;

    normalize_vector(&square.normal);
    denom = dot_product(square.normal, r.direction);
    if (fabs(denom) > 1e-6)
    {
        t_vector arbitray = create_v3(0, 1, 0);
        t_vector u = cross_product(arbitray, square.normal);
        if (equal(u))
            u = cross_product(create_v3(1, 0, 0), square.normal);
        t_vector v = cross_product(r.direction, u);
        normalize_vector(&u);
		normalize_vector(&v);
        p0l0 = substract(square.p, r.origin);
        t_min = dot_product(p0l0, square.normal) / denom;
        intersection = vector_add(r.origin, vector_multiply(r.direction, t_min));
        intersection = substract(intersection, square.p);
        double proj1 = dot_product(u, intersection);
        double proj2 = dot_product(v, intersection);
        if ((proj1 <= square.length / 2 && proj1 >= -(square.length / 2)) &&
            (proj2 <= square.length / 2 && proj2 >= -(square.length / 2)))
        {
            *t = t_min;
            return (1);
        }
    }
    return (0);
}
