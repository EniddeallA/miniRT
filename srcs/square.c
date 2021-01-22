/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:34 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/22 17:57:07 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	get_square_normal(t_square object)
{
	return (object.normal);
}

t_proj		calc_proj(t_square square)
{
	t_vector	arbitray;
	t_proj		p;

	arbitray = create_v3(0, 1, 0);
	p.u = cross_product(square.normal, arbitray);
	if (equal(p.u))
		p.u = cross_product(square.normal, create_v3(1, 0, 0));
	p.v = cross_product(p.u, square.normal);
	normalize_vector(&p.u);
	normalize_vector(&p.v);
	return (p);
}

int			intersect_with_square(t_ray r, t_square square, double *t)
{
	double		denom;
	t_proj		p;
	t_vector	oc;
	double		l;

	p = calc_proj(square);
	oc = substract(square.p, r.origin);
	denom = dot_product(oc, square.normal) / dot_product(square.normal, r.direction);
	if (fabs(denom) > 1e-6)
	{
		p.inter = vector_add(r.origin, vector_multiply(r.direction, denom));
		p.inter = substract(p.inter, square.p);
		p.proj1 = dot_product(p.u, p.inter);
		p.proj2 = dot_product(p.v, p.inter);
		l = square.length / 2;
		if ((p.proj1 <= l && p.proj1 >= -l) && (p.proj2 <= l && p.proj2 >= -l))
		{
			*t = denom;
			return (1);	
		}
	}
	return (0);
}

