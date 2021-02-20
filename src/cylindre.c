/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:38:44 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:45:13 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

double			intersection_ray_cylindre(t_obj *cyl, t_ray r)
{
	t_vect		f;
	t_vect		g;
	t_vect		abc;
	double		delta;
	double		t;

	g = sub_vect(r.origine, cyl->position);
	f = sub_vect(r.direction, vect_mult_val(cyl->direction,
				vect_scal(r.direction, cyl->direction)));
	g = sub_vect(g, vect_mult_val(cyl->direction,
				vect_scal(g, cyl->direction)));
	abc.x = get_norm_2(f);
	abc.y = 2 * vect_scal(f, g);
	abc.z = get_norm_2(g) - (cyl->radius * cyl->radius);
	delta = abc.y * abc.y - 4 * abc.x * abc.z;
	t = find_solution(delta, abc);
	cyl->hit = add_vect(r.origine, vect_mult_val(r.direction, t));
	cyl->norm = get_normalized(sub_vect(sub_vect(cyl->hit, cyl->position),
				vect_mult_val(cyl->direction, vect_scal(cyl->direction,
						sub_vect(cyl->hit, cyl->position)))));
	return (t);
}
