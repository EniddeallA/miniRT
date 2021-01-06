/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:09:18 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/06 17:25:48 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int			equal(t_vector v)
{
	return (v.x == 0 && v.y == 0 && v.z == 0);
}

t_matrix	create_m(t_vector right, t_vector up, t_vector direction,
						t_vector origin)
{
	t_matrix	m;

	m.m[0][0] = right.x;
	m.m[0][1] = right.y;
	m.m[0][2] = right.z;
	m.m[1][0] = up.x;
	m.m[1][1] = up.y;
	m.m[1][2] = up.z;
	m.m[2][0] = direction.x;
	m.m[2][1] = direction.y;
	m.m[2][2] = direction.z;
	m.m[3][0] = origin.x;
	m.m[3][1] = origin.y;
	m.m[3][2] = origin.z;
	return (m);
}

t_matrix	look_at(t_vector origin, t_vector direction)
{
	t_vector	right;
	t_vector	up;
	t_vector	arbitray;

	arbitray = create_v3(0, 1, 0);
	normalize_vector(&arbitray);
	if (equal((right = cross_product(arbitray, direction))))
	{
		arbitray = create_v3(1, 0, 0);
		normalize_vector(&arbitray);
		if (equal((right = cross_product(arbitray, direction))))
		{
			arbitray = create_v3(0, 0, 1);
			normalize_vector(&arbitray);
			right = cross_product(arbitray, direction);
		}
	}
	up = cross_product(direction, right);
	normalize_vector(&right);
	normalize_vector(&up);
	return (create_m(right, up, direction, origin));
}

t_vector	multiply_matrix(t_matrix m, t_vector v)
{
	t_vector	res;

	res.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0];
	res.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1];
	res.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2];
	return (res);
}
