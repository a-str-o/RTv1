/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:48:37 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:48:42 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void			sdl_error(char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(-1);
}

void			init_sdl(t_all *data)
{
	data->win = NULL;
	data->rend = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		sdl_error("initialisation SDL");
	if (!(data->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN)))
		sdl_error("Creation window");
	if (!(data->rend = SDL_CreateRenderer(data->win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		sdl_error("Creation render");
	if (SDL_SetRenderDrawColor(data->rend, 0, 255, 255, 255) != 0)
		sdl_error("Get color failed");
}

void			loop_program(t_all *data)
{
	SDL_bool	prog_launched;
	SDL_Event	event;

	SDL_RenderPresent(data->rend);
	prog_launched = SDL_TRUE;
	while (prog_launched)
	{
		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_KEYDOWN &&
					event.key.keysym.sym == SDLK_ESCAPE)
						|| event.type == SDL_QUIT)
			{
				free(data->light);
				ft_free_obj(data);
				prog_launched = SDL_FALSE;
			}
		}
	}
	SDL_DestroyRenderer(data->rend);
	SDL_DestroyWindow(data->win);
	SDL_Quit();
}
