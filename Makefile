NAME = cub3D

SRCS = srcs/main.c \
	srcs/parsing/check.c srcs/parsing/map.c \
	srcs/parsing/wall.c srcs/parsing/check_map.c srcs/parsing/texture.c \
	srcs/parsing/check_map_utils.c srcs/parsing/color.c \
	srcs/init.c srcs/utils.c \
	srcs/flood_fill.c  srcs/mlx.c  \
	srcs/free.c  srcs/event.c  \
	srcs/utils2.c srcs/color_conversion.c\
		

OBJS = ${SRCS:.c=.o}

CC = gcc -Wall -Wextra -Werror -g3

MLX = ./MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

RM = rm -rf

LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C ./libft
		$(CC) $(OBJS) $(MLX) $(LIB) -o $(NAME)


debug: $(OBJS)
		@make -C ./libft
		$(CC) -fsanitize=address $(OBJS) $(LIB) $(MLX) -o $(NAME)

clean:
	$(RM) $(LIB) $(OBJS)
	@$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all