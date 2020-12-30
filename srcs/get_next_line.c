/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:50:29 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:26:27 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

char	*resize(t_memory *mem)
{
	char	*partition;
	int		current_length;
	int		i;
	int		y;

	current_length = ft_strlen(mem->str) - mem->position;
	mem->lenght = current_length;
	if (!(partition = malloc(sizeof(char) * (BUFFER_SIZE + mem->lenght + 1))))
		return (0);
	i = mem->position;
	y = 0;
	while (mem->str[i])
		partition[y++] = mem->str[i++];
	partition[y] = '\0';
	free(mem->str);
	mem->str = partition;
	mem->position = 0;
	return (partition);
}

int		parse_mem(int fd, t_memory *mem)
{
	char	*partition;
	int		ret;

	partition = "1";
	if (!mem->str || mem->fd != fd)
	{
		mem->position = 0;
		mem->lenght = 0;
		if (!(mem->str = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	else
		partition = resize(mem);
	mem->fd = fd;
	if ((ret = read(fd, mem->str + mem->lenght, BUFFER_SIZE)) == -1
			|| !partition)
	{
		free(mem->str);
		mem->str = NULL;
		return (-1);
	}
	(mem->str)[mem->lenght + ret] = '\0';
	return (ret);
}

int		find_nl(t_memory *mem)
{
	int		i;
	char	*str;

	i = 0;
	str = &(mem->str)[mem->position];
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		copy_to_line(t_memory *mem, char **line)
{
	int	i;
	int	line_size;

	if (find_nl(mem) == -1)
		line_size = ft_strlen(&(mem->str)[mem->position]);
	else
		line_size = find_nl(mem);
	if ((*line = malloc(sizeof(char) * (line_size + 1))) == NULL)
		return (-1);
	i = 0;
	while (i < line_size)
	{
		(*line)[i] = (mem->str)[mem->position++];
		i++;
	}
	mem->position++;
	(*line)[i] = '\0';
	return (line_size);
}

int		get_next_line(int fd, char **line)
{
	int					ret;
	static	t_memory	mem;
	int					line_size;

	if (fd < 0 || BUFFER_SIZE == 0 || !line)
		return (-1);
	if ((ret = parse_mem(fd, &mem)) == -1)
		return (-1);
	while (ret >= BUFFER_SIZE && find_nl(&mem) == -1)
		if ((ret = parse_mem(fd, &mem) == -1))
			return (-1);
	if ((line_size = copy_to_line(&mem, line)) == -1)
		return (-1);
	if (ret < BUFFER_SIZE && line_size >= ft_strlen(mem.str))
	{
		free(mem.str);
		mem.str = NULL;
		return (-1);
	}
	else if (ret == -1)
		return (-1);
	return (1);
}
