/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:46:07 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:26:02 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!allowed_symbol(line[i]) && i > 2)
			return (0);
		i++;
	}
	return (1);
}

void	handle_error(char *error)
{
	write(2, "Error :\n", 8);
	write(2, error, ft_strlen(error));
	exit(-1);
}

int		check_fields(char **splitted)
{
	int i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

void	check_scene(t_scene *scene)
{
	if (scene->cameras == NULL)
		handle_error("Scene is missing cameras.");
	if (scene->ambient.r < 0 || scene->ambient.g < 0
	|| scene->ambient.b < 0)
		handle_error("Ambient light range : ([0-255]).");
	if (scene->width <= 0 || scene->height <= 0)
		handle_error("Width and height must be positive.");
	if (scene->width > 2560)
		scene->width = 2560;
	if (scene->height > 1440)
		scene->height = 1440;
}

void	check_color(t_fcolor color)
{
	if (color.r < 0 || color.r > 1 || color.g < 0 || color.g > 1 ||
		color.b < 0 || color.b > 1)
		handle_error("Color range : ([0-255])");
}
