/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:57:29 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/26 19:12:33 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct data
{
	int		height;
	int		width;
	char	**map;
	char	**map2;
	char	*texture;
	void	*win;
	void	*mlx;
	void	*wall;
	void	*player;
	void	*tiles;
	void	*coin;
	void	*door;
	void	*dooropen;
	int		count;

}			t_data;

typedef struct s_posistion
{
	int		x;
	int		y;
}			t_position;

// int  keycode(int keycode, t_position *position);
void		check_if_valid_player(t_data *data, int i, int flag, int flag2);
t_position	get_player_pos(t_data *data);
char		*ft_strchr(const char *s, int c);
void		ft_read_map(t_data *data, char *file);
void		ft_hieght(t_data *data, char *file);
char		*get_next_line(int fd);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*linesub(char *line_buffer);
char		*mybuffer(int fd, char *accumulation, char *buffer);
void		ft_free(char **buffer);
void		print_error(char *str);
void		ft_check(t_data *data);
void		ifthemapisvalid(t_data *data);
int			ft_strlen1(char *s);
size_t		ft_strlen(const char *s);
void		check_walls(t_data *data);
void		check_walls_helper(t_data *data);
void		flood_fill(t_data *data);
void		ft_copy(t_data *data);
int			map_dyali(t_data *data, char *file);
void		check_dotber(char **av);
void		parsingall(int ac, char **av);
void		ft_free1(char **str);
void		put_images(t_data *data);
void		print2DArray(char **arr, int rows, int cols);
void		render_map(t_data *data);

/////////////////////////////////////////////////////keycodefunciton

char		*ft_strjoin1(char *s1, char const *s2);
char		**ft_split(char const *s, char c);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
int			calculatecoin(t_data *data);
void		destroyimage(t_data *data);
void		put_the_image_on(t_data *data, int i, int j);
void		ft_putchar(char c);
void		ft_putnbr(int n);
int			exit_from_window(t_data *data);
int			calculatecoin(t_data *data);
int			keycode(int keycode, t_data *data);
void		handletextures(t_data *data);
#endif
