/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:16:51 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/27 19:17:40 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

typedef struct  s_pixel
{
    unsigned char r;
	unsigned char g;
	unsigned char b;
}               t_pixel;

t_pixel     **create_buffer(int height, int width);
void        free_buffer(t_pixel **buffer, int height);
t_pixel     pix_from_int(int color);

#endif