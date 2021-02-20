/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:48:49 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:48:54 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

double			intersection_ray_sphere(t_obj *sph, t_ray r)
{
	t_vect		abc;
	double		delta;
	double		t;

	abc.x = get_norm_2(r.direction);
	abc.y = 2 * vect_scal(r.direction, sub_vect(r.origine, sph->position));
	abc.z = get_norm_2(sub_vect(r.origine, sph->position))
		- (sph->radius * sph->radius);
	delta = abc.y * abc.y - 4 * abc.x * abc.z;
	t = find_solution(delta, abc);
	sph->hit = add_vect(r.origine, vect_mult_val(r.direction, t));
	sph->norm = get_normalized(sub_vect(sph->hit, sph->position));
	return (t);
}

int				f_str2(char **str, int j, int d)
{
	int			k;

	k = 0;
	if (check_str2(str, j, d) == -1)
		return (-1);
	if (j < d)
	{
		if (ft_val(str[k]) || ft_val(str[k + 1])
				|| ft_val(str[k + 2]))
			return (-1);
	}
	else if (j == d)
	{
		if (ft_val2(str[k]) || ft_val2(str[k + 1])
				|| ft_val2(str[k + 2]))
			return (-1);
	}
	return (1);
}
