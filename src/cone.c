/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:38:38 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:45:03 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void			hit_norm(t_obj *cone, t_ray r, double t)
{
	double		k;
	double		m;

	k = tan((cone->radius * PI / 180) / 2);
	m = vect_scal(r.direction, vect_mult_val(cone->direction, t))
		+ vect_scal(sub_vect(r.origine, cone->position), cone->direction);
	cone->hit = add_vect(r.origine, vect_mult_val(r.direction, t));
	cone->norm = get_normalized(sub_vect(sub_vect(cone->hit, cone->position)
				, vect_mult_val(cone->direction, (1 + k + k) * m)));
}

double			find_solution(double delta, t_vect abc)
{
	t_vect		t;

	if (delta <= 0)
		return (-1);
	t.x = (-1 * abc.y - sqrt(delta)) / (2 * abc.x);
	t.y = (-1 * abc.y + sqrt(delta)) / (2 * abc.x);
	if (t.y < 0 && t.x < 0)
		return (-1);
	else if (t.x > 0 && t.y < 0)
		t.z = t.x;
	else if (t.y > 0 && t.x < 0)
		t.z = t.y;
	else
		t.z = fmin(t.x, t.y);
	if (t.z <= 1e-4)
		return (-1);
	return (t.z);
}

double			intersection_ray_cone(t_obj *cone, t_ray r)
{
	t_vect		abc;
	t_vect		cp;
	t_vect		vd;
	double		angle;
	double		t;

	angle = cone->radius * PI / 180;
	vd = sub_vect(r.origine, cone->position);
	cp.x = vect_scal(vd, cone->direction);
	cp.y = vect_scal(r.direction, cone->direction);
	abc.x = (get_norm_2(sub_vect(r.direction,
			vect_mult_val(cone->direction, cp.y))) * pow(cos(angle), 2))
		- (pow(cp.y, 2) * pow(sin(angle), 2));
	abc.y = 2 * ((vect_scal(sub_vect(r.direction,
		vect_mult_val(cone->direction, cp.y)), sub_vect(vd,
		vect_mult_val(cone->direction, cp.x)))
		* pow(cos(angle), 2)) - (cp.y * cp.x * pow(sin(angle), 2)));
	abc.z = (get_norm_2(sub_vect(vd, vect_mult_val(cone->direction, cp.x))) *
			pow(cos(angle), 2)) - (pow(cp.x, 2) * pow(sin(angle), 2));
	cp.z = abc.y * abc.y - 4 * abc.x * abc.z;
	t = find_solution(cp.z, abc);
	hit_norm(cone, r, t);
	return (t);
}
