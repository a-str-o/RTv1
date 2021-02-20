/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:45:53 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:45:57 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		f_cone(char **str, int j, t_obj *cone)
{
	int		k;

	k = 0;
	if (j == 0)
		init_vect(&cone->position, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 1)
		init_vect(&cone->direction, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 2)
		init_vect(&cone->translation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 3)
		init_vect(&cone->rotation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 4)
		init_vect(&cone->color, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 5)
		cone->radius = ft_atof(str[k]);
}

int			s_cone(char **table, int i, t_all *data, t_obj *cone)
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
		f_cone(str, j, cone);
		j++;
		i++;
	}
	data->id++;
	cone->id = data->id;
	cone->direction = rot_vect_xyz(cone->direction,
			cone->rotation);
	cone->position = trans_vect_xyz(cone->position,
			cone->translation);
	cone->inter = &intersection_ray_cone;
	return (0);
}
