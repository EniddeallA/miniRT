/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:03:59 by akhalid           #+#    #+#             */
/*   Updated: 2021/01/04 15:21:35 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct	s_matrix
{
	double		m[4][4];
}				t_matrix;

t_matrix		look_at(t_vector origin, t_vector direction);
t_vector		multiply_matrix(t_matrix m, t_vector v);

#endif
