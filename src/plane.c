/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:47:58 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:48:03 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

double		intersection_ray_plan(t_obj *pln, t_ray r)
{
	double	nomi;
	double	dinomi;
	double	t;

	nomi = vect_scal(sub_vect(r.origine, pln->position),
			pln->direction);
	dinomi = vect_scal(r.direction, pln->direction);
	if ((dinomi == 0) || (nomi <= 0 && dinomi < 0)
			|| (nomi >= 0 && dinomi > 0))
		return (-1);
	t = -nomi / dinomi;
	if (t < 0)
		return (-1);
	pln->hit = add_vect(r.origine,
			vect_mult_val(r.direction, t));
	pln->norm = get_normalized(pln->direction);
	return (t);
}
