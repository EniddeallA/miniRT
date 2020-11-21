/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:13:07 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/21 16:54:41 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int main(int argc, char *argv[])
{
    int fd;
    
    
    if (argc < 2 || argc > 3)
        return (0);
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (argc == 2)
            minirt(fd, 0);
        else
            minirt(fd, 1);
    }
    
    return (0);
}