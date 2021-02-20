/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:46:21 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:46:25 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		f_plane(char **str, int j, t_obj *plane)
{
	int		k;

	k = 0;
	if (j == 0)
		init_vect(&plane->position, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 1)
		init_vect(&plane->direction, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 2)
		init_vect(&plane->translation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 3)
		init_vect(&plane->rotation, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 4)
		init_vect(&plane->color, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
}

int			s_plane(char **table, int i, t_all *data, t_obj *plane)
{
	int		j;
	int		k;
	char	**str;

	j = 0;
	while (table[i] && j < 5)
	{
		k = 0;
		str = ft_strsplit(table[i], ' ');
		if (f_str2(str, j, 4) == -1)
			return (-1);
		f_plane(str, j, plane);
		j++;
		i++;
	}
	data->id++;
	plane->id = data->id;
	plane->direction = rot_vect_xyz(plane->direction,
			plane->rotation);
	plane->position = trans_vect_xyz(plane->position,
			plane->translation);
	plane->inter = &intersection_ray_plan;
	return (0);
}
