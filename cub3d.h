/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2023/12/06 12:48:42 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define M_PI 3.14159265358979323846

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
    char *floor_color;
    char *ceilling_color;
    int ceilling[3];
    int floor[3];
    int horizontale;
    int verticale;  
    int r;
    int g;
    int b;
} t_cub;


typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_mlx
{
    mlx_t *id;
}   t_mlx;

typedef struct s_player
{
    t_point position;
    double direction;
}   t_player;


//init
void init(t_cub *cub);
void color_init(t_color *color);

//map
//char **read_map(char *file);
char **read_map(char *file, t_cub *cub);
void check_map(char **map);
void find_pos(char **map,t_player *player);

//flood fill
t_point find_start(char **map);
void flood_fill(char **map,int horizontale,int verticale);
void fill_bis(char **map,t_point cur,t_cub *cub);

//free
void free_cub(t_cub *cub);

//check
int check_map_extension(char *str, t_cub *cub);
void check_args(char argc);
int	ft_open_fd(char *filename);
void	check_file_extension(char *file);

//check_map
char **get_map(char **map);

//wall
int	check_closed_around_space(char **map);
void check_wall(char **map);

//color 
void check_color_arr(char **arr);
int color_range(t_cub *cub);
void	convert_rgb(char *line, t_cub *cub, char c);
void get_color(char *line, t_cub *cub);
void check_color(t_cub *cub);
void parse_floor(t_cub *cub);

//mlx
void open_window(t_mlx *mlx);

//utils
void print_arr(char **arr);
int ft_arrlen(char **map);
void free_arr(char **map);
int count_line(char **map);

#endif
