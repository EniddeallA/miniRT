/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:40:58 by akhalid           #+#    #+#             */
/*   Updated: 2020/12/30 15:07:36 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	parse_plane(t_scene *s, char **split)
{
	t_object	*obj;
	t_plane		*plane;

	if (check_fields(split) != 4)
		handle_error("Plane : Field missing/overflow");
	obj = malloc(sizeof(t_object));
	plane = malloc(sizeof(t_plane));
	parse_coords(&(plane->p), split[1]);
	parse_coords(&(plane->normal), split[2]);
	normalize_vector(&(plane->normal));
	parse_color(&(obj->color), split[3]);
	check_color(obj->color);
	obj->type = PLANE;
	obj->ptr = plane;
	ft_lstaddback(&(s->objects), ft_lstnew(obj));
}

void	parse_sphere(t_scene *s, char **split)
{
	t_object	*obj;
	t_sphere	*sphere;

	if (check_fields(split) != 4)
		handle_error("Sphere : Field missing/overflow");
	obj = malloc(sizeof(t_object));
	sphere = malloc(sizeof(t_sphere));
	parse_coords(&(sphere->p), split[1]);
	sphere->radius = ft_atod(split[2]) / 2;
	parse_color(&(obj->color), split[3]);
	check_color(obj->color);
	obj->type = SPHERE;
	obj->ptr = sphere;
	ft_lstaddback(&(s->objects), ft_lstnew(obj));
}

void	parse_square(t_scene *s, char **split)
{
	t_object	*obj;
	t_square	*square;

	if (check_fields(split) != 5)
		handle_error("Square : Field missing/overflow");
	obj = malloc(sizeof(t_object));
	square = malloc(sizeof(t_square));
	parse_coords(&(square->p), split[1]);
	parse_coords(&(square->normal), split[2]);
	normalize_vector(&(square->normal));
	square->length = ft_atod(split[3]);
	parse_color(&(obj->color), split[4]);
	check_color(obj->color);
	obj->type = SQUARE;
	obj->ptr = square;
	ft_lstaddback(&(s->objects), ft_lstnew(obj));
}

void	parse_cylinder(t_scene *s, char **split)
{
	t_object	*obj;
	t_cylinder	*cylinder;

	if (check_fields(split) != 6)
		handle_error("Cylinder : Field missing/overflow");
	obj = malloc(sizeof(t_object));
	cylinder = malloc(sizeof(t_cylinder));
	parse_coords(&(cylinder->p), split[1]);
	parse_coords(&(cylinder->normal), split[2]);
	normalize_vector(&(cylinder->normal));
	cylinder->radius = ft_atod(split[3]) / 2;
	cylinder->height = ft_atod(split[4]);
	parse_color(&(obj->color), split[5]);
	check_color(obj->color);
	obj->type = CYLINDER;
	obj->ptr = cylinder;
	ft_lstaddback(&(s->objects), ft_lstnew(obj));
}

void	parse_triangle(t_scene *s, char **split)
{
	t_object	*obj;
	t_triangle	*triangle;

	if (check_fields(split) != 5)
		handle_error("Triangle : Field missing/overflow");
	obj = malloc(sizeof(t_object));
	triangle = malloc(sizeof(t_triangle));
	parse_coords(&(triangle->p0), split[1]);
	parse_coords(&(triangle->p1), split[2]);
	parse_coords(&(triangle->p2), split[3]);
	parse_color(&(obj->color), split[4]);
	check_color(obj->color);
	obj->type = TRIANGLE;
	obj->ptr = triangle;
	ft_lstaddback(&(s->objects), ft_lstnew(obj));
}
