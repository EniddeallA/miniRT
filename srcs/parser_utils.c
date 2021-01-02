/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:59:30 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/30 15:05:27 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	parse_coords(t_vector *v, char *str)
{
	char	**split;

	split = ft_split(str, ',');
	if (check_fields(split) != 3)
		handle_error("Field missing/overflow");
	v->x = ft_atod(split[0]);
	v->y = ft_atod(split[1]);
	v->z = ft_atod(split[2]);
}

int		line_fields(char **splitted)
{
	int i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

int		allowed_symbol(char c)
{
	if (c == '\t' | c == ' ' | c == '\n' | c == '.' || c == ',' || c == '#' ||
	(c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}
