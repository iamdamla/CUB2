/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/03 13:08:54 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void load_img(t_cub *cub)
{
    //mlx->cub->bigmap = mlx_new_image(mlx->id, HEIGHT, WIDTH);
   // mlx->cub->minimap = mlx_new_image(mlx->id, (WIDTH / 3), (HEIGHT / 3));
    cub->north_tex = mlx_load_png(cub->pathNorth);
    cub->south_tex = mlx_load_png(cub->pathSouth);
    cub->east_tex = mlx_load_png(cub->pathEast);
    cub->west_tex = mlx_load_png(cub->pathWest);
    if(!cub->north_tex || !cub->south_tex || !cub->east_tex || !cub->west_tex)
    {
        printf("Error loading images!\n");
        //free_cub(mlx->cub);
        exit(1);
    }
   // mlx_image_to_window(mlx->id, mlx->cub->bigmap, 0, 0);
   // mlx_image_to_window(mlx->id, mlx->cub->minimap, 0,  WIDTH - ((WIDTH / 3) / MINIMAP) * MINIMAP);
}
