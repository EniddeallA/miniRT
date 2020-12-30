/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:27:40 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/30 15:07:56 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_vector	create_v3(double x, double y, double z)
{
	t_vector v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double		vector_len(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double		dot_product(t_vector a, t_vector b)
{
	double sum;

	sum = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (sum);
}

void		normalize_vector(t_vector *vector)
{
	double len;

	len = sqrt(vector->x * vector->x + vector->y
	* vector->y + vector->z * vector->z);
	vector->x /= len;
	vector->y /= len;
	vector->z /= len;
}
