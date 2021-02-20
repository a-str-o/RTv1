/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:37:40 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:37:41 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WIN_W       1000
# define WIN_H       1000
# define PI          3.14159265359

# include "vector.h"
# include "ray.h"
# include "data.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <SDL2/SDL.h>
# include "vector.h"
# include <math.h>

int					ft_val(char *str);
int					ft_val2(char *str);
int					ft_camera(char **table, t_all *data);
int					ft_obj(char **table, t_all *data);
int					check_str2(char **str, int j, int k);
int					f_str(char **str, int j, int k);
int					check_str1(char **str, int j, int k);
int					f_str2(char **str, int j, int d);
int					ft_cylinder(char **table, t_all *data);
int					ft_light(char **table, t_all *data);
int					file_checker(char *str, t_all *data);
int					s_sphere(char **table, int i, t_all *data, t_obj *sphere);
int					s_plane(char **table, int i, t_all *data, t_obj *plane);
int					s_cone(char **table, int i, t_all *data, t_obj *cone);
int					s_cylinder(char **table, int i,
								t_all *data, t_obj *cylinder);
void				loop_program(t_all *data);
void				init_sdl(t_all *data);
void				ft_lstdel(t_obj **alst);
void				sdl_error(char *message);
void				ft_alloc_light(t_data_light **light);
void				ft_alloc_obj(t_obj **obj);
void				raytracing(t_all data);
void				ft_free_obj(t_all *data);
t_vect				light_obj(t_obj *obj,
								t_data_light *light, t_ray ray, double t);
t_vect				on_shadow(t_obj *pos, t_all data, t_ray ray, t_vect col);
t_ray				init_rayy(int i, int j, t_data_camera *cam);
t_ray				init_rayy(int i, int j, t_data_camera *cam);
double				find_obj_scnd(t_all data,
									t_ray ray, t_ray to_light, t_obj *pos);
double				ft_atof(char *str);
double				find_solution(double delta, t_vect abc);
double				intersection_ray_sphere(t_obj *obj, t_ray r);
double				intersection_ray_plan(t_obj *obj, t_ray r);
double				intersection_ray_cylindre(t_obj *obj, t_ray r);
double				intersection_ray_cone(t_obj *cone, t_ray r);

#endif
