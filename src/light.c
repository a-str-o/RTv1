/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:47:36 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:47:41 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

t_vect			light_obj(t_obj *obj, t_data_light *light, t_ray ray, double t)
{
	t_vect		col;
	double		ambi;
	double		diff;
	double		spec;
	t_vect		rm;

	rm = get_normalized(sub_vect(light->position, obj->hit));
	rm = sub_vect(vect_mult_val(obj->norm, 2 * vect_scal(rm, obj->norm)), rm);
	ambi = 0.1;
	diff = fmax(0.0, 0.6 * vect_scal(get_normalized(
					sub_vect(light->position, obj->hit)), obj->norm));
	spec = 1 * pow(fmax(0.0, vect_scal(rm, get_normalized(
						sub_vect(ray.origine, obj->hit)))), 40);
	col.x = fmin(255, obj->color.x + ambi + light->color.x *
			diff + light->color.x * spec * light->intensity / (4 * PI *
				pow(get_norm_2(sub_vect(light->position, obj->hit)), 2)));
	col.y = fmin(255, obj->color.y + ambi + light->color.y *
			diff + light->color.y * spec * light->intensity / (4 * PI *
				pow(get_norm_2(sub_vect(light->position, obj->hit)), 2)));
	col.z = fmin(255, obj->color.z + ambi + light->color.z * diff +
			light->color.z * spec * light->intensity / (4 * PI *
				pow(get_norm_2(sub_vect(light->position, obj->hit)), 2)));
	return (col);
}

t_vect			on_shadow(t_obj *pos, t_all data, t_ray ray, t_vect col)
{
	t_vect		hit_sec;
	t_vect		norm_light;
	double		dis_shad_lum;
	double		dis_shad_inter;
	double		t1;

	norm_light = get_normalized(sub_vect(data.light->position, pos->hit));
	init_ray(&data.light->to_light, add_vect(pos->hit,
				vect_mult_val(norm_light, 1)), norm_light);
	t1 = find_obj_scnd(data, ray, data.light->to_light, pos);
	if (t1 != -1)
	{
		hit_sec = add_vect(pos->hit, vect_mult_val(
					data.light->to_light.direction, t1));
		dis_shad_inter = get_norm_2(sub_vect(hit_sec, pos->hit)) *
			get_norm_2(sub_vect(hit_sec, pos->hit));
		dis_shad_lum = get_norm_2(sub_vect(data.light->position, pos->hit)) *
			get_norm_2(sub_vect(data.light->position, pos->hit));
		if ((dis_shad_lum > dis_shad_inter))
			init_vect(&col, col.x * 0.7, col.y * 0.7, col.z * 0.7);
	}
	return (col);
}
