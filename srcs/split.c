/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:07:39 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/06 15:40:22 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static int		count_substrings(char const *s, char c)
{
	int		strings;
	size_t	i;

	i = 0;
	strings = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			strings++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	strings += 1;
	return (strings);
}

static size_t	to_sep(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	y;
	size_t	i;
	size_t	j;

	i = 0;
	y = 0;
	if (!s || !(result = malloc(sizeof(char *) * (count_substrings(s, c) + 1))))
		return (NULL);
	while (s[i] && !(j = 0))
	{
		if ((i > 1 && s[i - 1] == c && s[i - 2] == c) || (i == 0 && s[i] == c))
			handle_error("Format error.");
		if (s[i] != c && s[i])
		{
			result[y] = malloc(sizeof(char *) * (to_sep(&s[i], c) + 1));
			while (s[i] != c && s[i])
				result[y][j++] = s[i++];
			result[y++][j] = '\0';
		}
		while (s[i] == c && s[i])
			i++;
	}
	result[y] = NULL;
	return (result);
}
