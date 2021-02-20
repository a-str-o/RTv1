/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:47:48 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:47:52 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		ft_alloc(t_all *data)
{
	data->camera = (t_data_camera*)malloc(sizeof(t_data_camera));
	ft_alloc_obj(&data->obj);
	ft_alloc_light(&data->light);
}

int			main(int ac, char **av)
{
	t_all	data;

	if (ac == 2)
	{
		ft_alloc(&data);
		if (file_checker(av[1], &data) == -1)
		{
			ft_putendl("error file");
			return (0);
		}
		raytracing(data);
	}
	else
	{
		ft_putendl("Usage : ./RTv1 <...> ");
	}
	return (0);
}
