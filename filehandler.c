/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filehandler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:26:39 by akhalid           #+#    #+#             */
/*   Updated: 2020/10/16 17:59:43 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void errorHandler(char *str)
{
    write(1, str, ft_strlen(str));
}

void handleRtFile(char *line, t_scene *s, t_object *o)
{
	if (line[0] == 'R' || line[0] == 'A')
		sceneInfo(line , s);
	else if (line[0] == 'p' || line[0] == 't' || (line[0] == 's' && line[1] == 'p') ||
		(line[0] == 's' && line[1] == 'q') || (line[0] == 'c' && line[1] == 'y') || 
        line[0] == 'c' || line[0] == 'l')
		objectsInfo(line, o);
	else
		errorHandler("");
}

void sceneInfo(char *line, t_scene *s)
{
	if (line[0] == 'R')
		resolutionInfo(line, &s->res);
	else if (line[0] == 'A')
		ambientLightInfo(line, &s->al);
}

void objectsInfo(char *line, t_object *o)
{
    if (line[0] == 'c')
		cameraInfo(line, &o->ca);
	else if (line[0] == 'l')
		lightInfo(line, &o->l);
	else if (line[0] == 'c' && line[1] == 'y')
		cylinderInfo(line, &o->cy);
	else if (line[0] == 'p')
	 	planeInfo(line, &o->pl);
	else if (line[0] == 's' && line[1] == 'p')
		sphereInfo(line, &o->sp);
	else if (line[0] == 's' && line[1] == 'q')
		squareInfo(line, &o->sq);
	else if (line[0] == 't')
		triangleInfo(line, &o->tr);
}

void resolutionInfo(char *line, t_resolution *res)
{
    if ((res->x = ft_atoi(&line)) <= 0 ||
		(res->y = ft_atoi(&line)) <= 0)
		errorHandler("");
}

void ambientLightInfo(char *line, t_ambientLight *al)
{
    if ((al->ratio = ft_strtof(&line)) <= 0 || (al->color.x = ft_atoi(&line)) <= 0 ||
		(al->color.y = ft_atoi(&line)) <= 0 || (al->color.z = ft_atoi(&line)) <= 0)
		errorHandler("");
}

void cameraInfo(char *line, t_camera **c)
{
	t_camera *new;
	t_camera *temp;

	new = (t_camera*)malloc(sizeof(t_camera));
	new->viewPoint.x = ft_atoi(&line);
	new->viewPoint.y = ft_atoi(&line);
	new->viewPoint.z = ft_atoi(&line);
	new->orientationt_vector.x = ft_atoi(&line);
	new->orientationt_vector.y = ft_atoi(&line);
	new->orientationt_vector.z = ft_atoi(&line);
	new->FOV = ft_atoi(&line);
	new->next = NULL;
	if (*c == NULL)
	{
		*c = new;
		return;
	}
	temp = *c;
	while (temp->next)
			temp = temp->next;
	temp->next = new;
}

void lightInfo(char *line, t_light **l)
{
	t_light *new;
	t_light *temp;

	new = (t_light*)malloc(sizeof(t_light));
	new->lightPoint.x = ft_atoi(&line);
	new->lightPoint.y = ft_atoi(&line);
	new->lightPoint.z = ft_atoi(&line);
	new->lightBrightness = ft_strtof(&line);
	new->color.x = ft_atoi(&line);
	new->color.y = ft_atoi(&line);
	new->color.z = ft_atoi(&line);
	new->next = NULL;
	if (*l == NULL)
	{
		*l = new;
		return;
	}
	temp = *l;
	while (temp->next)
			temp = temp->next;
	temp->next = new;
}

void planeInfo(char *line, t_plane **p)
{
	t_plane *new;
	t_plane *temp;

	new = (t_plane*)malloc(sizeof(t_plane));
	new->planeCoordinates.x = ft_atoi(&line);
	new->planeCoordinates.y = ft_atoi(&line);
	new->planeCoordinates.z = ft_atoi(&line);
	new->orientationt_vector.x = ft_strtof(&line);
	new->orientationt_vector.y = ft_strtof(&line);
	new->orientationt_vector.z = ft_strtof(&line);
	new->color.x = ft_atoi(&line);
	new->color.y = ft_atoi(&line);
	new->color.z = ft_atoi(&line);
	new->next = NULL;
	if (*p == NULL)
	{
		*p = new;
		return;
	}
	temp = *p;
	while (temp->next)
			temp = temp->next;
	temp->next = new;
}

void squareInfo(char *line, t_square **sq)
{
	t_square *new;
	t_square *temp;

	new = (t_square*)malloc(sizeof(t_square));
	new->squareCenter.x = ft_atoi(&line);
	new->squareCenter.y = ft_atoi(&line);
	new->squareCenter.z = ft_atoi(&line);
	new->orientationt_vector.x = ft_strtof(&line);
	new->orientationt_vector.y = ft_strtof(&line);
	new->orientationt_vector.z = ft_strtof(&line);
	new->sideSize = ft_atoi(&line);
	new->color.x = ft_atoi(&line);
	new->color.y = ft_atoi(&line);
	new->color.z = ft_atoi(&line);
	new->next = NULL;
	if (*sq == NULL)
	{
		*sq = new;
		return;
	}
	temp = *sq;
	while (temp->next)
			temp = temp->next;
	temp->next = new;
}

void sphereInfo(char *line, t_sphere **sp)
{
	t_sphere *new;
	t_sphere *temp;

	new = (t_sphere*)malloc(sizeof(t_sphere));
	new->sphereCenter.x = ft_atoi(&line);
	new->sphereCenter.y = ft_atoi(&line);
	new->sphereCenter.z = ft_atoi(&line);
	new->sphereDiameter = ft_atoi(&line);
	new->color.x = ft_atoi(&line);
	new->color.y = ft_atoi(&line);
	new->color.z = ft_atoi(&line);
	new->next = NULL;
	if (*sp == NULL)
	{
		*sp = new;
		return;
	}
	temp = *sp;
	while (temp->next)
			temp = temp->next;
	temp->next = new;
}

void cylinderInfo(char *line, t_cylinder **cy)
{
	t_cylinder *new;
	t_cylinder *temp;

	new = (t_cylinder*)malloc(sizeof(t_cylinder));
	new->cylinderCoordinates.x = ft_strtof(&line);
	new->cylinderCoordinates.y = ft_strtof(&line);
	new->cylinderCoordinates.z = ft_strtof(&line);
	new->orientationt_vector.x = ft_strtof(&line);
	new->orientationt_vector.y = ft_strtof(&line);
	new->orientationt_vector.z = ft_strtof(&line);
	new->cylinderDiameter = ft_strtof(&line);
	new->cylinderheight = ft_strtof(&line);
	new->color.x = ft_atoi(&line);
	new->color.y = ft_atoi(&line);
	new->color.z = ft_atoi(&line);
	new->next = NULL;
	if (*cy == NULL)
	{
		*cy = new;
		return;
	}
	temp = *cy;
	while (temp->next)
			temp = temp->next;
	temp->next = new;
}

void triangleInfo(char *line, t_triangle **tr)
{
	t_triangle *new;
	t_triangle *temp;

	new = (t_triangle*)malloc(sizeof(t_triangle));
	new->trianglePoins_1.x = ft_atoi(&line);
	new->trianglePoins_1.y = ft_atoi(&line);
	new->trianglePoins_1.z = ft_atoi(&line);
	new->trianglePoins_2.x = ft_atoi(&line);
	new->trianglePoins_2.y = ft_atoi(&line);
	new->trianglePoins_2.z = ft_atoi(&line);
	new->trianglePoins_3.x = ft_atoi(&line);
	new->trianglePoins_3.y = ft_atoi(&line);
	new->trianglePoins_3.z = ft_atoi(&line);
	new->color.x = ft_atoi(&line);
	new->color.y = ft_atoi(&line);
	new->color.z = ft_atoi(&line);
	new->next = NULL;
	if (*tr == NULL)
	{
		*tr = new;
		return;
	}
	temp = *tr;
	while (temp->next)
			temp = temp->next;
	temp->next = new;
}

// void readRtFile(int fd)
// {
// 	char *buff;
//     ssize_t res;
//     char *line;
//     t_scene s;
//     t_object o;

//     ft_memset(&s, 0, sizeof(s));
//     ft_memset(&o, 0, sizeof(o));
//     if ( fd <= 0 || !(buff = (char*)malloc(sizeof(char*) * 100)) )
//         return;
//     line = ft_strdup("");
//     while((res = read(fd, buff, 1)) > 0)
//     {
//         buff[res] = '\0';
//         line = ft_strjoin(line, buff);
//         if (ft_strchr(line, '\n') == 1)
//         {
//             handleRtFile(line, &s, &o);
//             free(line);
//             line = NULL;
//             line = ft_strdup("");
//         }
//     }
//     free(buff);
// 	free(line);
// 	raytrace(s, o);
// }

t_scene *readRtFile(int fd)
{
	

} 