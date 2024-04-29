CC = cc
CFLAGS = -Wall -Wextra -Werror
mlx = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
SRCS = 	get_next_line.c get_next_line_utils.c \
		ft_split.c \
		check_map.c check_map_utils.c check_map_utils2.c\
		print_map.c move_player.c \
		moving_up_down.c moving_left_right.c \
		ft_putstr_fd.c main.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) so_long.h
	$(CC) $(CFLAGS) $(SRCS) $(mlx) -o $(NAME)

clean : 
	$(RM) $(OBJS)
fclean:clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all