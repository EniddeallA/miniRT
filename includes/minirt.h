/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:18:51 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/22 17:30:52 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <mlx.h>

#include "list.h"

typedef struct  s_color
{
    float r;
    float g;
    float b;
}               t_color;

typedef struct  s_scene
{
    int width;
    int height;
    double ambient_ratio;
    t_color ambient;
    t_list *cameras;
    t_list *lights;
    t_list *objects;
}               t_scene;


typedef	struct	s_image {
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct  s_options
{
    t_scene *scene;
    void    *mlx;
    void    *window;
    t_image image;
}               t_options;


void minirt(int fd, int save);


#endif