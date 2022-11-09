# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 16:16:41 by deelliot          #+#    #+#              #
#    Updated: 2022/11/09 11:51:04 by deelliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address 
# FLAGS += -fsanitize=address -Wconversion -Ofast -flto

# Directories
SRCS_DIR = srcs
OBJS_DIR = objs
INCS = -I includes/ -I libft/includes/ -I minilibx/
HDRS = includes/RTv1.h \
	includes/colour_and_light.h \
	includes/matrices.h \
	includes/objects.h \
	includes/tuple.h \
	includes/world.h \
	includes/patterns.h
LIBFT_DIR = libft
MINILIBX_DIR = minilibx

# Source and object files
FILES = \
	main \
	initialise \
	image \
	error_handling \
	tuple_operations \
	matrix_maths \
	matrix_inversion \
	handle_input \
	intersect \
	matrix_transformations \
	plot \
	normals \
	transform_tuple \
	reflections \
	sphere \
	cylinder \
	cone \
	world \
	view_transform \
	shading \
	camera \
	ray \
	render \
	colour \
	computations \
	sphere_scene \
	plane \
	patterns \
	pattern_world \
	parse

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

# Paths
LIBFT_A = $(LIBFT_DIR)/libft.a
MINILIBX_A = $(MINILIBX_DIR)/libmlx.a
LIBS = $(LIBFT_A) $(MINILIBX_A)

# Libraries
LINKS = \
	-lm \
	-L $(LIBFT_DIR) -lft \
	-L $(MINILIBX_DIR) -lmlx \
	-framework OpenGL -framework Appkit

# iMac minilibx:
# LINKS = -L /usr/local/lib -lmlx -I /usr/local/include -framework \
# 	OpenGL -framework AppKit

#Rules
all: libft $(NAME)

$(NAME): .prerequisites $(LIBS) $(OBJS) Makefile
	touch .prerequisites
	gcc $(FLAGS) $(INCS) $(LINKS) $(OBJS) -o $(NAME)
	@echo "Usage: ./RTV1 + option"
	@echo "options: >> ??"

$(OBJS): $(OBJS_DIR)%.o:$(SRCS_DIR)%.c $(HDRS) Makefile
	gcc $(FLAGS) $(INCS) -o $@ -c $<

.prerequisites: $(OBJS_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
libft:
	make -C $(LIBFT_DIR)
$(MINILIBX_A):
	make -C $(MINILIBX_DIR)

clean:
	/bin/rm -Rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)
	@echo " Objects removed"

fclean: clean
	/bin/rm -f $(NAME) .prerequisites
	make -C $(LIBFT_DIR) fclean
	@echo " $(NAME) removed "

re: fclean all

.PHONY: all clean fclean re libft
