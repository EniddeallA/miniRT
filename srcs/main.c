/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:13:07 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/29 17:39:22 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	minirt(int fd, int save)
{
	t_options	options;

	options.scene = parse_scene(fd);
	options.camera_number = 0;
	if (save == 1)
	{
		render(0, &options, 1);
		return ;
	}
	options.mlx = mlx_init();
	options.window = mlx_new_window(options.mlx, options.scene->width,
									options.scene->height, "miniRT");
	options.image.img = mlx_new_image(options.mlx, options.scene->width,
										options.scene->height);
	options.image.addr = (int *)mlx_get_data_addr(options.image.img,
										&(options.image.bits_per_pixel),
										&(options.image.line_length),
										&(options.image.endian));
	mlx_hook(options.window, 17, 0, fexit, &options);
	mlx_key_hook(options.window, rerender, &options);
	render(0, &options, 0);
	mlx_loop(options.mlx);
}

int		main(int argc, char *argv[])
{
	int		fd;

	if (argc < 2 || argc > 3)
		return (0);
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		if (argc == 2)
			minirt(fd, 0);
		else if (!ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
			minirt(fd, 1);
	}
	return (0);
}
