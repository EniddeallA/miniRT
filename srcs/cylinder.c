/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:38 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/04 15:17:01 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	get_cylinder_normal(t_vector hit_point, t_cylinder object)
{
	t_vector	result;
	t_vector	n;

	n = substract(hit_point, object.p);
	result = substract(n, vector_multiply(object.normal
						, dot_product(object.normal, n)));
	normalize_vector(&result);
	return (result);
}

void		calculate_m(double *t, t_ray r, t_cylinder cylinder)
{
	t_vector	q;
	t_vector	p2;

	p2 = vector_add(cylinder.p, vector_multiply(cylinder.normal
					, cylinder.height));
	q = vector_add(r.origin, vector_multiply(r.direction, *t));
	if (dot_product(cylinder.normal, substract(q, cylinder.p)) <= 0)
		*t = -1;
	if (dot_product(cylinder.normal, substract(q, p2)) >= 0)
		*t = -1;
}

int			cylinder_quadratic(t_ray r, t_cylinder cylinder, double *t0
								, double *t1)
{
	t_vector	a_sqrt;
	t_vector	right;
	double		a;
	double		b;
	double		c;

	a_sqrt = substract(r.direction,
								vector_multiply(cylinder.normal,
								dot_product(r.direction, cylinder.normal)));
	a = dot_product(a_sqrt, a_sqrt);
	right = substract(substract(r.origin, cylinder.p),
						vector_multiply(cylinder.normal,
							dot_product(substract(r.origin, cylinder.p),
							cylinder.normal)));
	b = 2 * dot_product(a_sqrt, right);
	c = dot_product(right, right) - (cylinder.radius * cylinder.radius);
	if (!solve_quadratic(quadratic_params(a, b, c), t0, t1))
		return (0);
	return (1);
}

int			intersect_with_cylinder(t_ray r, t_cylinder cylinder, double *t)
{
	double	t0;
	double	t1;

	if (!cylinder_quadratic(r, cylinder, &t0, &t1))
		return (0);
	if (t0 > 0)
		calculate_m(&t0, r, cylinder);
	if (t1 > 0)
		calculate_m(&t1, r, cylinder);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		*t = t1 > 0 ? t1 : t0;
	if (t0 < t1)
		*t = t0 > 0 ? t0 : t1;
	return (1);
}
