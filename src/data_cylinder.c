/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:46:09 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:46:13 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		f_cylinder(char **str, int j, t_obj *cylinder)
{
	int		k;

	k = 0;
	if (j == 0)
		init_vect(&cylinder->position, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 1)
		init_vect(&cylinder->direction, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 2)
		init_vect(&cylinder->translation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 3)
		init_vect(&cylinder->rotation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 4)
		init_vect(&cylinder->color, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 5)
		cylinder->radius = ft_atof(str[k]);
}

int			s_cylinder(char **table, int i, t_all *data, t_obj *cylinder)
{
	int		j;
	int		k;
	char	**str;

	j = 0;
	while (table[i] && j < 6)
	{
		k = 0;
		str = ft_strsplit(table[i], ' ');
		if (f_str(str, j, 4) == -1)
			return (-1);
		f_cylinder(str, j, cylinder);
		j++;
		i++;
	}
	data->id++;
	cylinder->id = data->id;
	cylinder->direction = rot_vect_xyz(cylinder->direction,
			cylinder->rotation);
	cylinder->position = trans_vect_xyz(cylinder->position,
			cylinder->translation);
	cylinder->inter = &intersection_ray_cylindre;
	return (0);
}
