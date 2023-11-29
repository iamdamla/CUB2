/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2023/11/29 12:39:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_color
{
    int r;
    int g;
    int b;
    int a;
} t_color;

typedef struct s_cub
{
    char **map;
  
    t_color		floor_color;
	t_color		ceiling_color;
    int horizontale;
    int verticale;  
} t_cub;

typedef struct s_getcolor
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;
	char	**colors;
	t_color	rgba;
}			t_getcolor;

typedef struct s_point
{
    int x;
    int y;
}   t_point;



//init
void init(t_cub *cub);
void color_init(t_color *color);

//map
char **read_map(char *file);
void check_map(char **map);


//check
int check_map_extension(char *str, t_cub *cub);
void check_args(char argc);
int	ft_open_fd(char *filename);
void	check_file_extension(char *file);

//wall
int	check_closed_around_space(char **map);
void check_wall(char **map);

//color 
int get_color(char *str, t_cub *cub, int mode);

//check map
char **get_map(char **map);

//utils
void print_arr(char **arr);
int ft_arrlen(char **map);
void free_arr(char **map);
int count_line(char **map);

#endif
