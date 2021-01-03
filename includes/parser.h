/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:38:12 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/26 17:28:27 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "vector.h"
# include "color.h"

t_scene	*parse_scene(int fd);
void	parse_line(t_scene *s, char **split);
void	parse_resolution(t_scene *s, char **split);
void	parse_ambient(t_scene *s, char **split);
void	parse_camera(t_scene *s, char **split);
void	parse_light(t_scene *s, char **split);
void	parse_plane(t_scene *s, char **split);
void	parse_square(t_scene *s, char **split);
void	parse_sphere(t_scene *s, char **split);
void	parse_cylinder(t_scene *s, char **split);
void	parse_triangle(t_scene *s, char **split);
void	parse_coords(t_vector *v, char *str);
void	parse_color(t_fcolor *c, char *str);
void	parse_normal(t_vector *v, char *str);

#endif