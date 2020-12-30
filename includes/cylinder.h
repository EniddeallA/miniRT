/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:53:02 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/17 17:07:46 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "ray.h"
# include "vector.h"


typedef struct  s_cylinder
{
    t_vector	p;
    t_vector	normal;
    double      radius;
    double      height;
}               t_cylinder;

int         intersect_with_cylinder(t_ray r, t_cylinder cylinder, double *t);
int         cylinder_quadratic(t_ray r, t_cylinder cylinder, double *t0, double *t1);
void        calculate_m(double *t, t_ray r, t_cylinder cylinder);
t_vector    get_cylinder_normal(t_vector hit_point, t_cylinder object);

#endif