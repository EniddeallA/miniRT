/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:07:12 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/26 17:14:54 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "includes.h"

typedef struct  s_vector
{
    double x;
    double y;
    double z;
}               t_vector;

t_vector        create_v3(double x, double y, double z);
double          vector_len(t_vector v);
double          dot_product(t_vector a, t_vector b);
t_vector        substract(t_vector vec1, t_vector vec2);
void            normalize_vector(t_vector *vector);
t_vector        vector_add(t_vector vec1, t_vector vec2);
t_vector        vector_multiply(t_vector vec1, double x);
t_vector        cross_product(t_vector a, t_vector b);

#endif