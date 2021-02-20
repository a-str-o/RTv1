/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:46:34 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:46:38 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		f_light(char **str, int j, t_data_light *light)
{
	int		k;

	k = 0;
	if (j == 0)
		init_vect(&light->position, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 1)
		init_vect(&light->color, ft_atof(str[k]),
				ft_atof(str[k + 1]), ft_atof(str[k + 2]));
	if (j == 2)
		light->intensity = ft_atof(str[k]);
}

int			s_light(char **table, int i, t_data_light *light)
{
	int		j;
	int		k;
	char	**str;

	j = 0;
	while (table[i] && j < 3)
	{
		k = 0;
		str = ft_strsplit(table[i], ' ');
		if (f_str(str, j, 1) == -1)
			return (-1);
		f_light(str, j, light);
		j++;
		i++;
	}
	return (0);
}

int			ft_light(char **table, t_all *data)
{
	int		i;
	int		a;
	char	**aray;

	i = 0;
	a = 0;
	aray = table;
	while (table[i])
	{
		if (ft_strcmp("light", table[i]) == 0 && a == 0)
		{
			a = 1;
			if (s_light(aray, i + 1, (*data).light) < 0)
				return (-1);
		}
		i++;
	}
	return (0);
}
