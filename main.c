/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:26:11 by akhalid           #+#    #+#             */
/*   Updated: 2020/10/26 12:16:00 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minirt.h"

 int main()
 {
     //int argc, char **argv
    int fd;

    // if (argc == 1)
    //     write(1, "'.rt' file not provided", ft_strlen("'.rt' file not provided"));
    // else if(argc == 2)
    // {
    //     fd = open(argv[2], O_RDONLY);
    //     readRtFile(fd);
    // }
    fd = open("./file.rt", O_RDONLY);
    readRtFile(fd);
 }