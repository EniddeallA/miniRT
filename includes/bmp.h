/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:03:17 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:43:17 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "pixel.h"

# define PIXEL_DATA_OFFSET 54
# define HEADER_SIZE 40
# define PLANES 1
# define BITS_PER_PIXEL 24

int		write_bmp(char *filename, unsigned int width, 
					unsigned int height, t_pixel **pixels);
void	fill_header(unsigned char *header, unsigned int width, 
						unsigned int height);
void	write_file(unsigned int height, unsigned int width,
					t_pixel **pixels, int fd);

#endif