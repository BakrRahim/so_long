CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = so_long

SRCS = ft_check_format.c \
	ft_check_path.c \
	ft_move.c \
	ft_split.c \
	ft_strncmp.c \
	so_long_utils.c \
	so_long_utils2.c \
	so_long.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	ft_printf/libftprintf.a \

PRINTF = ft_printf

all : $(NAME)

$(NAME) :
	make -C $(PRINTF)
	$(CC) $(SRCS) $(CFLAGS) $(MLX) -o $(NAME)

clean :
	make clean -C $(PRINTF)

fclean :
	make fclean -C $(PRINTF)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re