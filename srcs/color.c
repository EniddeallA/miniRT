/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:46:08 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:50:25 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int			icolor_to_int(t_icolor c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

t_icolor	int_to_icolor(int rgb)
{
	t_icolor	c;

	c.r = rgb >> 16 & 0xFF;
	c.g = rgb >> 8 & 0xFF;
	c.b = rgb & 0xFF;
	return (c);
}

int			fcolor_to_int(t_fcolor a)
{
	int			result;
	t_icolor	this;

	this.r = a.r * 256;
	this.g = a.g * 256;
	this.b = a.b * 256;
	result = icolor_to_int(this);
	return (result);
}

t_fcolor	icolor_to_fcolor(t_icolor ic)
{
	t_fcolor	fc;

	fc.r = (float)ic.r / 256;
	fc.g = (float)ic.g / 256;
	fc.b = (float)ic.b / 256;
	return (fc);
}
