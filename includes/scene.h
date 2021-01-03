/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:57:44 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/20 19:03:40 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "color.h"
# include "vector.h"
# include "minirt.h"

typedef enum	e_object_type
{
	SPHERE,
	PLANE,
	TRIANGLE,
	SQUARE,
	CYLINDER,
}				t_otype;

typedef struct	s_object
{
	t_otype		type;
	void		*ptr;
	t_fcolor	color;
}				t_object;

typedef struct	s_camera
{
	t_vector	origin;
	t_vector	direction;
	int			fov;
}				t_camera;

typedef struct	s_light
{
	t_vector	origin;
	double		intensity;
	t_fcolor	color;
}				t_light;

void			init_scene(t_scene *scene);

#endif