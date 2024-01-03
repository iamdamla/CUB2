/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:39:03 by derblang          #+#    #+#             */
/*   Updated: 2024/01/03 15:51:15 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void build_wall(t_mlx *mlx)
// {
//     size_t height;
//    t_ray *ray = &(mlx->raycast);

//     int x = 0;
//     int y = 0;
//     while(x < WIDTH - 1)
//     {
//         y = 0;
//         while(y < HEIGHT - 1)
//         {
//            height = (4000 / ray->dist_player_screen);
//            y = 0 - height;
//            y++;
//         }
//         x++;
//         y = 0;
//     } 
//     printf("height -> %ld\n", height);
//     printf("ray->dist_player %d\n",ray->dist_player_screen);
//     printf("ray->dist_ray %d\n", ray->dist_ray);
   
// }


void build_wall(t_mlx *mlx)
{
    size_t height;
    t_ray *ray = &(mlx->raycast);

    int x = 0;
    int y = 0;
    
    while(x < WIDTH - 1)
    {
         
        while(y < HEIGHT - 1)
        {
            height = ((64.0 / ray->dist_player_screen) * 277.0);
            y = 0 - height;   
            mlx_put_pixel(mlx->screen, x, y, G025);
            y++;
        }
        x++;
        y = 0;
    }
     printf("height -> %ld\n", (size_t)height);
   // printf("y-> %d\n", y);
    // printf("ray->dist_player %d\n",ray->dist_player_screen);
    // printf("ray->dist_ray %d\n", ray->dist_ray);
}