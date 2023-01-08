CC = cc

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c \
		so_long_utils.c \
		check_map.c \
		move_player.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		libft/libft.a \

NAME = so_long

LIBFT = libft/libft.a

RM = rm -f

all : $(NAME)

$(NAME) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(LIBFT) :
	make -f libft/Makefile

clean : 
	make clean -f libft/Makefile

fclean : clean
	$(RM) $(NAME)

re : fclean all