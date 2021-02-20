/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:47:00 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:47:05 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		f_sphere(char **str, int j, t_obj *sphere)
{
	int k;

	k = 0;
	if (j == 0)
		init_vect(&sphere->position, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 1)
		init_vect(&sphere->translation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 2)
		init_vect(&sphere->rotation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 3)
		init_vect(&sphere->color, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 4)
		sphere->radius = ft_atof(str[k]);
}

int			s_sphere(char **table, int i, t_all *data, t_obj *sphere)
{
	int		j;
	int		k;
	char	**str;

	j = 0;
	while (table[i] && j < 5)
	{
		k = 0;
		str = ft_strsplit(table[i], ' ');
		if (f_str(str, j, 3) == -1)
			return (-1);
		f_sphere(str, j, sphere);
		j++;
		i++;
	}
	data->id++;
	sphere->id = data->id;
	sphere->direction = rot_vect_xyz(sphere->direction,
			sphere->rotation);
	sphere->position = trans_vect_xyz(sphere->position,
			sphere->translation);
	sphere->inter = &intersection_ray_sphere;
	return (0);
}
