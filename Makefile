# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:14:13 by yoelguer          #+#    #+#              #
#    Updated: 2020/02/22 15:55:05 by yoelguer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= 	main.c \
			plane.c\
			ray.c\
			sphere.c\
			cylindre.c\
			cone.c\
			vector.c\
			vector2.c\
			vector3.c\
			file.c\
			data_camera.c\
			data_sphere.c\
			data_malloc.c\
			data_plane.c\
			data_light.c\
			data_cone.c\
			data_cylinder.c\
			ft_atof.c\
			raytrace.c\
			val.c\
			light.c\
			sdl.c\

HEADER = 	header/data.h\
			header/ray.h\
			header/rt.h\
			header/vector.h\

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

NAME 	= RTv1

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE	= -I /Users/$$USER/.brew/Cellar/sdl2/2.0.14_1/include 

LIB = -L /Users/$$USER/.brew/Cellar/sdl2/2.0.14_1/lib 

SDL = -l SDL2-2.0.0

SRC_DIR = ./src

OBJ_DIR = ./obj

LIBFT_DIR = ./libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a


CC = @gcc 

all : $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT_LIB) $(OBJ)
	@gcc $(OBJ) $(CFLAGS) -o $(NAME) $(INCLUDE) $(LIB)  $(SDL) $(LIBFT_LIB)
	@echo "\033[92mDone for RTV1\033[0m"

$(OBJ_DIR):
	@-mkdir $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@gcc -c  $(INCLUDE) $< -o $@ 

clean :
	@make clean -C ./libft/
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

norme:
	@norminette $(SRC_DIR)

re : fclean all
