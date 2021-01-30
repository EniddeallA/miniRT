/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:07:48 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/30 15:32:37 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	fill_header(unsigned char *header, unsigned int width,
						unsigned int height)
{
	unsigned	int	pixels_in_row;
	unsigned	int	padding_in_row;

	ft_memset(header, 0, 54);
	header[0] = 'B';
	header[1] = 'M';
	pixels_in_row = width * sizeof(t_pixel);
	padding_in_row = (4 - (pixels_in_row % 4)) % 4;
	header[2] = 54 + (pixels_in_row + padding_in_row) * height;
	header[10] = PIXEL_DATA_OFFSET;
	header[14] = HEADER_SIZE;
	*(unsigned int *)(&header[18]) = width;
	*(unsigned int *)(&header[22]) = height;
	header[26] = PLANES;
	header[28] = BITS_PER_PIXEL;
}

void	write_file(unsigned int height, unsigned int width,
					t_pixel **pixels, int fd)
{
	unsigned int	pixels_in_row;
	unsigned int	padding_in_row;
	int				row;
	unsigned char	zeroes[3];

	zeroes[0] = 0;
	zeroes[1] = 0;
	zeroes[2] = 0;
	pixels_in_row = width * sizeof(t_pixel);
	padding_in_row = (4 - (pixels_in_row % 4)) % 4;
	row = height;
	while (row >= 0)
	{
		write(fd, pixels[row], pixels_in_row);
		write(fd, zeroes, padding_in_row);
		row--;
	}
}

int		write_bmp(char *filename, unsigned int width,
				unsigned int height, t_pixel **pixels)
{
	unsigned	char	header[54];
	int					fd;

	fill_header(header, width, height);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(fd, header, 54);
	write_file(height, width, pixels, fd);
	close(fd);
	return (0);
}
