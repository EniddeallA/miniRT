/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:16:20 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/30 14:49:17 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_pixel	**create_buffer(int height, int width)
{
	t_pixel	**buffer;
	int		i;

	i = 0;
	buffer = malloc(sizeof(t_pixel *) * height);
	while (i < height)
		buffer[i++] = malloc(sizeof(t_pixel) * width);
	return (buffer);
}

void	free_buffer(t_pixel **buffer, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(buffer[i++]);
	free(buffer);
}

t_pixel	pix_from_int(int color)
{
	t_icolor	ic;
	t_pixel		pixel;

	ic = int_to_icolor(color);
	pixel.b = ic.r;
	pixel.g = ic.g;
	pixel.r = ic.b;
	return (pixel);
}
