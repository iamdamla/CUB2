/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2023/12/18 13:05:25 by derblang         ###   ########.fr       */
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


typedef struct s_cub
{
    char **map;
    char *floor_color;
    char *ceilling_color;
    int horizontale;
    int verticale;  
    int floor[3];
    int ceilling[3];
    char *pathNorth;
    char *pathSouth;
    char *pathEast;
    char *pathWest;
} t_cub;



typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_player
{
    t_point position;
    double direction;
}   t_player;

typedef struct s_mlx
{
    mlx_t *id;
     mlx_image_t* img;
    t_player *player;
}   t_mlx;



//init
void init(t_cub *cub);

//map
char **read_map(char *file);
void find_pos(char **map,t_player *player);
t_cub check_all_map(char *file);


//flood fill

void flood_fill(char **map,int horizontale,int verticale);
void fill_bis(char **map,t_point cur,t_cub *cub);


//free
void free_cub(t_cub *cub);
void free_only_cub(t_cub *cub);

//check
int check_map_extension(char *str, t_cub *cub);
void check_args(char argc);
int	ft_open_fd(char *filename);
void	check_file_extension(char *file);


//check_map_utils
void texture_check(char *line, int *count);
char	**get_map_description(char **map);


//check_map
int invalid_char_check(char **map);
int check_map_components(char **map);

//wall
int	check_closed_around_space(char **map);
void check_wall(char **map);

//color 
void check_color_arr(char **arr);
void	convert_rgb(char *line, t_cub *cub, char c);
void get_color(char *line, t_cub *cub);
void check_color(t_cub *cub);
void parse_floor(t_cub *cub);
int color_range(t_cub *cub);


//mlx
void open_window(t_mlx *mlx,t_cub *cub,t_player *player);
void draw_character(t_mlx *mlx,int x,int y);
//events
void update_player_position(void *param);
void event(mlx_key_data_t event,void *content);
//utils
void print_arr(char **arr);
int ft_arrlen(char **map);
void free_arr(char **map);
int count_line(char **map);
char ** map_cpy(char **map,int verticale);
char	**ft_arrdup(char **arr);

//texture
void check_map_texture(char **map, t_cub *cub);
void check_map_color(char **map, t_cub *cub);


//utils2
int find_start_of_str(char *str, char *prefix);
#endif
