/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:26:11 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/19 23:37:27 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minirt.h"

 int main(int argc, char **argv)
 {
    int fd;

    if (argc < 2 || argc > 3)
		return (0);
	else
	{
        fd = open(argv[1], O_RDONLY);
		if (argc == 2)
			raytrace(fd, 0);
		else if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
			raytrace(fd, 1);
	}
	return (0);
}