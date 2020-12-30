/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:32 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:27:05 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	get_sphere_normal(t_vector hit_point, t_sphere object)
{
	t_vector	result;

	result = substract(hit_point, object.p);
	normalize_vector(&result);
	return (result);
}

t_quadratic	quadratic_params(double a, double b, double c)
{
	t_quadratic	q;

	q.a = a;
	q.b = b;
	q.c = c;
	return (q);
}

int			solve_quadratic(t_quadratic q, double *t0, double *t1)
{
	double	delta;
	double	x;

	delta = pow(q.b, 2) - 4 * q.a * q.c;
	if (delta < 0)
		return (0);
	else if (delta == 0)
	{
		*t0 = -0.5 * q.b / q.a;
		*t1 = -0.5 * q.b / q.a;
	}
	else
	{
		if (q.b > 0)
			x = -1 * (q.b + sqrt(delta)) / 2;
		else
			x = -1 * (q.b - sqrt(delta)) / 2;
		*t0 = x / q.a;
		*t1 = q.c / x;
	}
	if (*t0 > *t1)
		swap(t0, t1);
	return (1);
}

int			quadratic(double *t0, double *t1, t_sphere sphere, t_ray r)
{
	t_vector	l;
	double		a;
	double		b;
	double		c;

	l = substract(r.origin, sphere.p);
	a = dot_product(r.direction, r.direction);
	b = 2.0 * dot_product(r.direction, l);
	c = dot_product(l, l) - (sphere.radius * sphere.radius);
	if (!solve_quadratic(quadratic_params(a, b, c), t0, t1))
		return (0);
	return (1);
}

int			intersect_with_sphere(t_ray r, t_sphere sphere, double *t)
{
	double	t0;
	double	t1;

	if (!quadratic(&t0, &t1, sphere, r))
		return (0);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	return (1);
}
