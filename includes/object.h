/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:57:44 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/22 19:01:27 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "color.h"

typedef enum	e_object_type
{
	SPHERE,
	CUBE,
	PLANE,
	LIGHT,
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


#endif