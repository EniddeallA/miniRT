/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:52:59 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/03 15:36:23 by akhalid          ###   ########.fr       */
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

int				intersect_with_square(t_ray r, t_square square, double *t);
t_vector		get_square_normal(t_square object);

#endif