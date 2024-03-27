NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRCS = so_long.c read_map.c parsing.c get_next_line.c get_next_line_utils.c so_long_utils.c

OBJ = $(SRCS:.c=.o)

AR  = ar rcs

RM = rm -rf 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


 %.o: %.c 
     $(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean : 
		$(RM) $(OBJ)

fclean :
		$(RM) $(OBJ) $(NAME)

re : fclean all
