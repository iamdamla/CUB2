/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:36:38 by derblang          #+#    #+#             */
/*   Updated: 2024/01/04 14:44:03 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

// void draw_screen(t_mlx *mlx)
// {
//     int x;
//     int y;
//     t_ray *ray = &(mlx->raycast);

//     x = 0;
//     y = (HEIGHT * 64) / ray->dist_player_screen;
//     printf("y-> %d\n", y);
//     while(x < WIDTH)
//     {
//         while(y < HEIGHT)
//         {
//             mlx_put_pixel(mlx->screen,x,y,G025);
//             y++;
            
//         }
//         x++;
//         y = 0;
//     }
// }


// static double	deg2rad(int deg)
// {
// 	return (deg * (M_PI / 180));
// }

// void draw_screen(t_mlx *mlx)
// {
//     t_ray *ray = &(mlx->raycast);
//     int x = 0;
//     int y =0;
//     int line_height = (int)(HEIGHT / ray->dist_ray);
//     int draw_start = -line_height / 2 + HEIGHT / 2;
//     if(draw_start < 0)
//         draw_start = 0;
//     int draw_end = line_height / 2 + HEIGHT / 2;
//     if(draw_end >= HEIGHT)
//         draw_end = HEIGHT - 1;
//     verLine(x, draw_start, draw_end, G025);
//     draw_line(mlx, draw_start, draw_end, double angle)
//     while(x < WIDTH)
//     {
//         while(y < HEIGHT)
//         {
//             mlx_put_pixel(mlx->img,x,y,G025);
//             y++;
//         }
//         x++;
//         y = 0;
//     }
// }

void draw_screen(t_mlx *mlx)
{
    int x;
    int y;
    t_ray *ray = &(mlx->raycast);
    ray->fish_eyes = 
    x = 0;
    y = (HEIGHT * 64) / ray->dist_player_screen;
    while(x < WIDTH)
    {
        while(y < HEIGHT)
        {
            mlx_put_pixel(mlx->screen,x,y,G025);
            y++;
            
        }
        x++;
        y = 0;
    }
}