/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:48:25 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:48:32 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

double			find_obj_scnd(t_all data, t_ray ray, t_ray to_light, t_obj *pos)
{
	t_obj		*header;
	double		t;
	double		t1;

	t1 = -1;
	header = data.obj;
	while (header->next)
	{
		if (header->id == pos->id && (header = header->next))
			continue;
		t = header->inter(header, to_light);
		if (t != -1)
		{
			if (t1 == -1)
				t1 = t;
			else
			{
				if (t1 > t)
					t1 = t;
			}
		}
		header = header->next;
	}
	return (t1);
}

t_obj			*find_close(t_all data, t_ray ray)
{
	t_obj		*pos;
	t_obj		*header;
	double		t;
	double		t1;

	t1 = -1;
	header = data.obj;
	pos = header;
	while (header->next)
	{
		t = header->inter(header, ray);
		if (t != -1)
		{
			t1 == -1 ? pos = header : 0;
			t1 == -1 ? t1 = t : 0;
			t1 > t ? pos = header : 0;
			t1 > t ? t1 = t : 0;
		}
		header = header->next;
	}
	pos->t = t1;
	return (pos);
}

t_vect			rend_pix(t_all data, t_ray ray)
{
	t_vect		col;
	t_obj		*pos;

	col = new_vect(100, 100, 100);
	pos = find_close(data, ray);
	if (pos->t != -1)
	{
		col = light_obj(pos, data.light, ray, pos->t);
		col = on_shadow(pos, data, ray, col);
	}
	return (col);
}

void			raytracing(t_all data)
{
	int			j;
	int			i;
	t_ray		ray;
	t_vect		col;

	i = 0;
	init_sdl(&data);
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			ray = init_rayy(i, j, data.camera);
			col = rend_pix(data, ray);
			if (SDL_SetRenderDrawColor(data.rend,
						col.x, col.y, col.z, 255) != 0)
				sdl_error("Get color failed");
			if (SDL_RenderDrawPoint(data.rend, i, j) != 0)
				sdl_error("draw point failed");
			j++;
		}
		i++;
	}
	loop_program(&data);
}
