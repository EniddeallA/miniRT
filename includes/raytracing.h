/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:28:10 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/16 16:38:51 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "list.h"
# include "ray.h"
# include "scene.h"


int             intersert_with_all(t_list *obj, t_ray r, 
                                    t_object **closest_object, double *t_min);
int             intersect(t_ray r, t_object *obj, double *t);


#endif