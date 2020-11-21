/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:28:42 by akhalid           #+#    #+#             */
/*   Updated: 2020/03/11 16:47:01 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector vec(float x, float y, float z)
{
    t_vector v;
    
    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}

t_vector vec_plus(t_vector v1, t_vector v2)
{
    return (vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector vec_plusf(t_vector v1, float f)
{
    return (vec(v1.x + f, v1.y + f, v1.z + f));
}

t_vector vec_minus(t_vector v1, t_vector v2)
{
    return (vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector vec_X(t_vector v1, t_vector v2)
{
    return (vec(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

t_vector vec_frac(t_vector v1, t_vector v2)
{
    return (vec(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z));
}

t_vector vec_Xf(t_vector v1, float f)
{
    return (vec(v1.x * f, v1.y * f, v1.z * f));
}

t_vector vec_fracf(t_vector v1, float f)
{
    return (vec(v1.x / f, v1.y / f, v1.z / f));
}

float vec_dot(t_vector v1, t_vector v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float vec_length(t_vector v)
{
    return (sqrtf(vec_dot(v, v)));
}

t_vector vec_cross(t_vector v1, t_vector v2)
{
    return (vec(v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x));
}

t_vector normalize(t_vector v)
{
    return (vec_fracf(v, vec_length(v)));
}