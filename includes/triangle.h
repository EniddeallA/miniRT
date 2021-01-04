/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:43:29 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/04 15:24:05 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "ray.h"
# include "vector.h"

typedef struct	s_triangle
{
	t_vector	p0;
	t_vector	p1;
	t_vector	p2;
}				t_triangle;

int				intersect_with_triangle(t_ray r, t_triangle triangle,
											double *t);
int				inside_outside_test(t_triangle triangle, t_vector phit,
										t_vector n);
t_vector		get_triangle_normal(t_triangle object);

#endif
