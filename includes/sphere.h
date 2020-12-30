/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:52:50 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/16 12:25:15 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vector.h"
# include "ray.h"

typedef struct  s_sphere
{
    t_vector    p;
    double      radius;
}               t_sphere;

typedef struct  s_quadratic
{
    double a;
    double b;
    double c;
}               t_quadratic;

int             intersect_with_sphere(t_ray r, t_sphere sphere, double *t);
int             quadratic(double *t0, double *t1, t_sphere sphere, t_ray r);
int             solve_quadratic(t_quadratic q, double *t0, double *t1);
t_quadratic     quadratic_params(double a, double b, double c);
t_vector        get_sphere_normal(t_vector hit_point, t_sphere object);

#endif