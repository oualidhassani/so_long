NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c

OBJ = $(SRCS:.c=.o)

AR  = ar rcs

RM = rm -rf 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean : 
		$(RM) $(OBJ)

fclean :
		$(RM) $(OBJ) $(NAME)