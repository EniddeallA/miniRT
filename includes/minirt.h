/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:59:04 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/03 15:35:12 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "color.h"
# include "list.h"

typedef struct	s_scene
{
	int			width;
	int			height;
	double		ambient_ratio;
	t_fcolor	ambient;
	t_list		*cameras;
	t_list		*lights;
	t_list		*objects;
	int			selected_camera;
}				t_scene;

typedef	struct	s_image 
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_options
{
	t_scene		*scene;
	void		*mlx;
	void		*window;
	t_image		image;
	int			camera_number;
}				t_options;

void			minirt(int fd, int save);
void			render (int camera_number, t_options *options, int save);
void			send_rays(t_options *options, int save);
int				fexit(void);
int				rerender(int key, t_options *options);

#endif
