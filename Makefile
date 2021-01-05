# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/03 15:04:32 by akhalid           #+#    #+#              #
#    Updated: 2021/01/05 19:16:18 by akhalid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = minirt

SDIR = ./srcs/

SRC =	main.c				\
		minirt.c			\
		atod.c				\
		bmp.c				\
		color.c				\
		color_utils.c		\
		cylinder.c			\
		error_handlers.c	\
		error_handlers2.c	\
		get_next_line.c		\
		list.c				\
		matrix.c			\
		parse_components.c	\
		parse_objects.c		\
		parser_utils.c		\
		parsers.c			\
		pixel.c				\
		plane.c				\
		ray.c				\
		raytracing.c		\
		shading.c			\
		specular.c			\
		sphere.c			\
		split.c				\
		square.c			\
		triangle.c			\
		utils.c				\
		vector.c			\
		vector_utils.c		\

IDIR = ./includes/

CFLAGS = -Wall -Wextra -Werror -g

MLX = -lmlx -framework OpenGL -framework AppKit

SRCS =	$(addprefix $(SDIR), $(SRC)) ./srcs/main.c

OBJDIR = ./objs
OBJS =	$(OBJDIR)/*.o

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -I $(IDIR) $(MLX) $(OBJS) -o $(NAME)

$(OBJS):	$(SRCS)
			@$(CC) -c $(CFLAGS) $(SRCS)
			mv *.o $(OBJDIR)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re, bonus
