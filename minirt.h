/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 02:48:50 by akhalid           #+#    #+#             */
/*   Updated: 2020/11/17 17:32:21 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
    ** UTILS
*/

size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
int     ft_strchr(char *s, int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    *ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char **str);
float	ft_strtof(char **str);
float   calculateValue(int exponent, int res, int sig_digs);

/*
    ** VECTOR
*/

typedef struct  s_vector
{
    float       x;
    float       y;
    float       z;
}               t_vector;

t_vector    vec(float x, float y, float z);
t_vector    vec_plus(t_vector v1, t_vector v2);
t_vector    vec_plusf(t_vector v1, float f);
t_vector    vec_minus(t_vector v1, t_vector v2);
t_vector    vec_X(t_vector v1, t_vector v2);
t_vector    vec_frac(t_vector v1, t_vector v2);
t_vector    vec_Xf(t_vector v1, float f);
t_vector    vec_fracf(t_vector v1, float f);
float       vec_dot(t_vector v1, t_vector v2);
float       vec_length(t_vector v);
t_vector    normalize(t_vector v);
t_vector    vec_cross(t_vector v1, t_vector v2);

/*
    ** MINIRT
*/

typedef struct  s_resolution
{
    int         x;
    int         y;
}               t_resolution;

typedef struct  s_ambientLight
{
    float       ratio;
    t_vector    color;
}               t_ambientLight;

typedef struct      s_camera
{
    t_vector        viewPoint; // origin
    t_vector        orientationt_vector; // up t_vector
    int             FOV;
    struct s_camera *next;
}                   t_camera;

typedef struct      s_light
{
    t_vector        lightPoint;
    float           lightBrightness;
    t_vector        color;
    struct s_light  *next;
}                   t_light;

typedef struct      s_plane
{
    t_vector        planeCoordinates;
    t_vector        orientationt_vector;
    t_vector        color;
    struct s_plane  *next;
}                   t_plane;

typedef struct      s_sphere
{
    t_vector        sphereCenter;
    float           sphereDiameter;
    t_vector        color;
    int             material;
    struct s_sphere *next;
}                   t_sphere;

typedef struct      s_square
{
    t_vector        squareCenter;
    t_vector        orientationt_vector;
    float           sideSize;
    t_vector        color;
    struct s_square *next;
}   t_square;

typedef struct          s_cylinder
{
    t_vector            cylinderCoordinates;
    t_vector            orientationt_vector;
    float               cylinderDiameter;
    float               cylinderheight;
    t_vector            color;
    struct s_cylinder   *next;
}                       t_cylinder;

typedef struct          s_triangle
{
    t_vector            trianglePoins_1;
    t_vector            trianglePoins_2;
    t_vector            trianglePoins_3;
    t_vector            color;
    struct s_triangle   *next;
}                       t_triangle;

typedef struct      s_scene
{
    t_resolution    res;
    t_ambientLight  al;
}                   t_scene;

typedef struct  s_object
{
    t_camera    *ca;
    t_light     *l;
    t_plane     *pl;
    t_sphere    *sp;
    t_square    *sq;
    t_cylinder  *cy;
    t_triangle  *tr;
}               t_object;

typedef struct  s_material{
    t_vector    diffuse;
    float       reflection;
}               t_material;


void    readRtFile(int fd);
void    handleRtFile(char *line, t_scene *s, t_object *o);
void    objectsInfo(char *line, t_object *o);
void    sceneInfo(char *line, t_scene *o);
void    errorHandler(char *str);
void    resolutionInfo(char *line, t_resolution *res);
void    ambientLightInfo(char *line, t_ambientLight *al);
void    cameraInfo(char *line, t_camera **c);
void    lightInfo(char *line, t_light **l);
void    planeInfo(char *line, t_plane **p);
void    squareInfo(char *line, t_square **sq);
void    sphereInfo(char *line, t_sphere **sp);
void    cylinderInfo(char *line, t_cylinder **cy);
void    triangleInfo(char *line, t_triangle **tr);
void    raytrace(t_scene s, t_object o);
void    render(void *mlx, void *window, t_scene s, t_object o);

/*

    ** IMAGES

*/

typedef struct  s_img
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

int		argbconverter(int a, int r, int g, int b);
void    my_mlx_pixel_put(t_img *data, int x, int y, int color);