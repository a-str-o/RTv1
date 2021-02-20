/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:48:10 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:48:14 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		init_ray(t_ray *r, t_vect origine, t_vect direc)
{
	r->origine = origine;
	r->direction = direc;
}

t_ray		init_rayy(int i, int j, t_data_camera *cam)
{
	t_vect	s;
	t_ray	r;

	s = sub_vect(cam->pos, vect_mult_val(cam->dir, cam->dist));
	s = sub_vect(s, vect_mult_val(cam->u_dir, (i - (WIN_W / 2))));
	s = add_vect(s, vect_mult_val(cam->v_dir, ((WIN_H / 2) - j)));
	r.direction = sub_vect(s, cam->pos);
	r.origine = cam->pos;
	normalize(&(r.direction));
	return (r);
}
