/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:53:11 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/21 15:36:01 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void		parse_color(t_fcolor *c, char *str)
{
	char	**split;

	split = ft_split(str, ',');
	if (check_fields(split) != 3 || !check_rgb(split))
	{
		free_tab(split);
		handle_error("Color format : [R,G,B] <0,255>");
	}
	c->r = ft_atod(split[0]) / 256;
	c->g = ft_atod(split[1]) / 256;
	c->b = ft_atod(split[2]) / 256;
	if (c->r >= 1 || c->r < 0 || c->g >= 1 ||
		c->g < 0 || c->b >= 1 || c->b < 0)
		handle_error("Color range : <0,255>");
	free_tab(split);
}

void		parse_line(t_scene *s, char **split)
{
	if (line_fields(split) == 0)
		return ;
	else if (split[0][0] == '#')
		return ;
	else if (!ft_strncmp(split[0], "R", 1) && cmp(split[0], "R"))
		parse_resolution(s, split);
	else if (!ft_strncmp(split[0], "A", 1) && cmp(split[0], "A"))
		parse_ambient(s, split);
	else if (!ft_strncmp(split[0], "cy", 2) && cmp(split[0], "cy"))
		parse_cylinder(s, split);
	else if (!ft_strncmp(split[0], "c", 1) && cmp(split[0], "c"))
		parse_camera(s, split);
	else if (!ft_strncmp(split[0], "l", 1) && cmp(split[0], "l"))
		parse_light(s, split);
	else if (!ft_strncmp(split[0], "sp", 2) && cmp(split[0], "sp"))
		parse_sphere(s, split);
	else if (!ft_strncmp(split[0], "pl", 2) && cmp(split[0], "pl"))
		parse_plane(s, split);
	else if (!ft_strncmp(split[0], "sq", 2) && cmp(split[0], "sq"))
		parse_square(s, split);
	else if (!ft_strncmp(split[0], "tr", 2) && cmp(split[0], "tr"))
		parse_triangle(s, split);
	else
		handle_error("Unknown element in the scene.");
}

void		init_scene(t_scene *scene)
{
	scene->cameras = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
	scene->height = 0;
	scene->width = 0;
	scene->ambient.r = -1;
	scene->ambient.g = -1;
	scene->ambient.b = -1;
}

t_scene		*parse_scene(int fd)
{
	t_scene	*s;
	int		ret;
	char	*line;
	char	**split;

	if (!(s = malloc(sizeof(t_scene))))
		return (0);
	init_scene(s);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		split = ft_split(line, ' ');
		if (!check_line(line))
			handle_error("Scene contains unallowed symbols.");
		parse_line(s, split);
		free(line);
		free_tab(split);
	}
	split = ft_split(line, ' ');
	parse_line(s, split);
	free(line);
	free_tab(split);
	check_scene(s);
	close(fd);
	return (s);
}
