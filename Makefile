NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = so_long.c read_map.c parsing.c get_next_line.c get_next_line_utils.c so_long_utils.c implementation.c parsing2.c parsing3.c implementation_tools.c

OBJ = $(SRCS:.c=.o)

AR  = ar rcs

RM = rm -rf 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o so_long


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean : 
		$(RM) $(OBJ)

fclean :
		$(RM) $(OBJ) $(NAME)

re : fclean all