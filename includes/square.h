/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:52:59 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/22 15:29:40 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "ray.h"
# include "vector.h"

typedef struct	s_square
{
	t_vector	p;
	t_vector	normal;
	double		length;
}				t_square;

typedef struct	s_proj
{
	t_vector	u;
	t_vector	v;
	double		proj1;
	double		proj2;
	t_vector	inter;
}				t_proj;

int				intersect_with_square(t_ray r, t_square square, double *t);
t_vector		get_square_normal(t_square object);

#endif
