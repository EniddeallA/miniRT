/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:19:52 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/06 15:10:23 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	parse_resolution(t_scene *s, char **split)
{
	if (check_fields(split) != 3)
		handle_error("Resolution : Field missing/overflow.");
	if (s->width || s->height)
		handle_error("Resolution can only be set once in a scene.");
	if (!check_floaters(split[1]) || !check_floaters(split[2]))
		handle_error("Resolution can't be float.");
	s->width = ft_atoi(split[1]);
	s->height = ft_atoi(split[2]);
}

void	parse_ambient(t_scene *s, char **split)
{
	if (s->ambient.r != -1)
		handle_error("Ambient can only be set once in a scene.");
	if (check_fields(split) != 3)
		handle_error("Ambient : Field missing/overflow");
	s->ambient_ratio = ft_atod(split[1]);
	if (s->ambient_ratio < 0 || s->ambient_ratio > 1)
		handle_error("Ambient ratio range : [0.0,1.0].");
	parse_color(&(s->ambient), split[2]);
	check_color(s->ambient);
}

void	parse_camera(t_scene *s, char **split)
{
	t_camera	*c;

	if (check_fields(split) != 4)
		handle_error("Camera : Field missing/overflow.");
	c = malloc(sizeof(t_camera));
	parse_coords(&(c->origin), split[1]);
	parse_normal(&(c->direction), split[2]);
	normalize_vector(&(c->direction));
	if (!check_floaters(split[3]))
		handle_error("Camera FOV range : [0,180].");
	c->fov = ft_atoi(split[3]);
	if (c->fov < 0 || c->fov > 180)
		handle_error("Camera FOV range : [0,180].");
	ft_lstaddback(&(s->cameras), ft_lstnew(c));
}

void	parse_light(t_scene *s, char **split)
{
	t_light	*l;

	if (check_fields(split) != 4)
		handle_error("Light : Field missing/overflow.");
	l = malloc(sizeof(t_light));
	parse_coords(&(l->origin), split[1]);
	l->intensity = ft_atod(split[2]);
	parse_color(&(l->color), split[3]);
	check_color(l->color);
	ft_lstaddback(&(s->lights), ft_lstnew(l));
}
