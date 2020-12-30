/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:41:13 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/26 17:10:59 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLERS_H
# define ERROR_HANDLERS_H

# include "includes.h"

int     allowed_symbol(char c);
int		line_fields(char **splitted);
int     check_line(char *line);
void    handle_error(char *error);
void    check_scene(t_scene *s);
int		check_fields(char **splitted);
void	check_color(t_fcolor ambient);

#endif