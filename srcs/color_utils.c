/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:46:08 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/30 15:01:06 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_fcolor	int_to_fcolor(int color)
{
	t_icolor	this;
	t_fcolor	result;

	this = int_to_icolor(color);
	result.r = (float)this.r / 256;
	result.g = (float)this.g / 256;
	result.b = (float)this.b / 256;
	return (result);
}

t_fcolor	fcolor_add(t_fcolor a, t_fcolor b)
{
	t_fcolor	result;

	result.r = fmin(a.r + b.r, 0.99);
	result.g = fmin(a.g + b.g, 0.99);
	result.b = fmin(a.b + b.b, 0.99);
	return (result);
}

t_fcolor	fcolor_mult(t_fcolor a, t_fcolor b)
{
	t_fcolor	result;

	result.r = fmin(a.r * b.r, 1);
	result.g = fmin(a.g * b.g, 1);
	result.b = fmin(a.b * b.b, 1);
	return (result);
}

t_fcolor	fcolor_coeff(t_fcolor a, double coeff)
{
	t_fcolor	result;

	result.r = fmin(a.r * coeff, 1);
	result.g = fmin(a.g * coeff, 1);
	result.b = fmin(a.b * coeff, 1);
	return (result);
}

t_fcolor	rgb_to_fcolor(int r, int g, int b)
{
	t_fcolor	fc;

	fc.r = (float)r / 256;
	fc.g = (float)g / 256;
	fc.b = (float)b / 256;
	return (fc);
}
