/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:52:55 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/03 15:36:09 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "ray.h"
# include "vector.h"

typedef struct  s_plane
{
	t_vector	p;
	t_vector	normal;
}				t_plane;

int				intersect_with_plane(t_ray r, t_plane sphere, double *t);
t_vector		get_plane_normal(t_plane object);

#endif