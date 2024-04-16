#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 1
#endif
typedef struct data
{
    int height;
    int width;
    char **map;
    char **map2;
}t_data;

typedef struct s_posistion
{
    int x;
    int y;
}  t_position;

char	        *ft_strchr(const char *s, int c);
void            ft_read_map(t_data *data, char *file);
void            ft_hieght(t_data *data, char *file);
char	        *get_next_line(int fd);
int            ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*linesub(char *line_buffer);
char			*mybuffer(int fd, char *accumulation, char *buffer);
void			ft_free(char **buffer);
void            print_error(char *str);
void            ft_check(t_data *data);
void            ifthemapisvalid(t_data *data);
int 	        ft_strlen1(char *s);
size_t	        ft_strlen(const char *s);
void            check_walls(t_data *data);
void            check_walls_helper(t_data *data);
void            flood_fill(t_data *data);
void            ft_copy(t_data *data);
int             map_dyali(t_data *data, char *file);
void            check_dotber(char **av);
void ft_free1(char **str);
#endif