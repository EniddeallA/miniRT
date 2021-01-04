/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:36 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/04 15:16:32 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	get_triangle_normal(t_triangle triangle)
{
	t_vector	result;
	t_vector	a;
	t_vector	b;

	a = substract(triangle.p1, triangle.p0);
	b = substract(triangle.p2, triangle.p0);
	result = cross_product(a, b);
	normalize_vector(&result);
	return (result);
}

int			inside_outside_test(t_triangle triangle, t_vector phit, t_vector n)
{
	t_vector	perpendicular_vec;
	t_vector	edge;
	t_vector	vp;

	edge = substract(triangle.p1, triangle.p0);
	vp = substract(phit, triangle.p0);
	perpendicular_vec = cross_product(edge, vp);
	if (dot_product(n, perpendicular_vec) < 0)
		return (0);
	edge = substract(triangle.p2, triangle.p1);
	vp = substract(phit, triangle.p1);
	perpendicular_vec = cross_product(edge, vp);
	if (dot_product(n, perpendicular_vec) < 0)
		return (0);
	edge = substract(triangle.p0, triangle.p2);
	vp = substract(phit, triangle.p2);
	perpendicular_vec = cross_product(edge, vp);
	if (dot_product(n, perpendicular_vec) < 0)
		return (0);
	return (1);
}

int			intersect_with_triangle(t_ray r, t_triangle triangle, double *t)
{
	t_vector	p0p1;
	t_vector	p0p2;
	t_vector	n;
	double		angle;
	t_vector	phit;

	p0p1 = substract(triangle.p1, triangle.p0);
	p0p2 = substract(triangle.p2, triangle.p0);
	n = cross_product(p0p1, p0p2);
	normalize_vector(&n);
	angle = dot_product(n, r.direction);
	if (fabs(angle) < 1e-6)
		return (0);
	*t = dot_product(n, substract(triangle.p0, r.origin)) / angle;
	if (*t < 0)
		return (0);
	phit = vector_add(r.origin, vector_multiply(r.direction, *t));
	return (inside_outside_test(triangle, phit, n));
}
