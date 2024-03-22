#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
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
}t_data;


void ft_read_map(t_data *data, char *file);
void ft_hieght(t_data *data, char *file);
char	*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*linesub(char *line_buffer);
char			*mybuffer(int fd, char *accumulation, char *buffer);
void			ft_free(char **buffer);
void            print_error(char *str);
void        ft_check(t_data *data);
#endif