/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:41:13 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/04 15:24:37 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLERS_H
# define ERROR_HANDLERS_H

# include "includes.h"

int		allowed_symbol(char c);
int		line_fields(char **splitted);
int		check_line(char *line);
void	handle_error(char *error);
void	check_scene(t_scene *s);
int		check_fields(char **splitted);
void	check_color(t_fcolor ambient);
int		check_rgb(char **split);
int		check_floaters(char *split);
int		check_file(char *split);
void	free_tab(char **tab);

#endif
