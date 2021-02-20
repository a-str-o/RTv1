/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:37:09 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:37:15 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "ray.h"
# include "rt.h"
# include <SDL2/SDL.h>

typedef struct			s_data_camera
{
	t_vect				pos;
	t_vect				dir;
	t_vect				u_dir;
	t_vect				v_dir;
	double				dist;
}						t_data_camera;

typedef struct			s_data_light
{
	t_vect				position;
	t_vect				color;
	double				intensity;
	t_ray				to_light;
	struct s_data_light	*next;
}						t_data_light;

typedef struct			s_obj
{
	int					id;
	t_vect				position;
	t_vect				translation;
	t_vect				rotation;
	t_vect				color;
	t_vect				axis;
	t_vect				hit;
	t_vect				norm;
	t_vect				direction;
	double				(*inter)(struct s_obj *, t_ray);
	double				radius;
	double				t;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_all
{
	t_data_camera		*camera;
	t_data_light		*light;
	t_obj				*obj;
	SDL_Window			*win;
	SDL_Renderer		*rend;
	int					id;
}						t_all;

#endif
