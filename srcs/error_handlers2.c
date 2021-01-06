/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:46:07 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/06 14:33:14 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		check_floaters(char *split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (split[i] == '.')
			return (0);
		i++;
	}
	return (1);
}

int		check_rgb(char **split)
{
	int i;
	int j;

	i = check_fields(split) - 1;
	while (i)
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] == '.')
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

int		check_file(char *split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (split[i] == '.')
			if ((split[i - 1] >= 'a' && split[i - 1] <= 'z') ||
				(split[i - 1] >= 'A' && split[i - 1] <= 'Z') ||
				(split[i - 1] >= '0' && split[i - 1] <= '9'))
				return (1);
		i++;
	}
	return (0);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab[i]);
	free(tab);
}

int		cmp(char *s1, char *s2)
{
	return (ft_strlen(s1) == ft_strlen(s2));
}
