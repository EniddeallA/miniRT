/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:18:51 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/21 17:07:38 by akhalid          ###   ########.fr       */
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

typedef struct  s_scene
{
    
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