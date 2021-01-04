/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:39:43 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/04 15:22:33 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "includes.h"

typedef struct	s_fcolor
{
	float		r;
	float		g;
	float		b;
}				t_fcolor;

typedef struct	s_icolor
{
	int			r;
	int			g;
	int			b;
}				t_icolor;

int				icolor_to_int(t_icolor c);
t_icolor		int_to_icolor(int rgb);
t_fcolor		int_to_fcolor(int color);
t_fcolor		icolor_to_fcolor(t_icolor a);
t_fcolor		fcolor_add(t_fcolor a, t_fcolor b);
t_fcolor		fcolor_mult(t_fcolor a, t_fcolor b);
t_fcolor		fcolor_coeff(t_fcolor a, double coeff);
t_fcolor		rgb_to_fcolor(int r, int g, int b);
int				fcolor_to_int(t_fcolor a);

#endif
