/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/02 15:54:18 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void load_img(t_mlx *mlx)
{
    mlx->cub->bigmap = mlx_new_image(mlx->id, HEIGHT, WIDTH);
    mlx->cub->minimap = mlx_new_image(mlx->id, (WIDTH / 3), (HEIGHT / 3));
    mlx->cub->north_tex = mlx_load_png(mlx->cub->pathNorth);
    mlx->cub->south_tex = mlx_load_png(mlx->cub->pathSouth);
    mlx->cub->east_tex = mlx_load_png(mlx->cub->pathEast);
    mlx->cub->west_tex = mlx_load_png(mlx->cub->pathWest);
    if(!mlx->cub->north_tex || !mlx->cub->south_tex || !mlx->cub->east_tex || !mlx->cub->west_tex)
    {
        printf("Error loading images!\n");
        //free_cub(mlx->cub);
        exit(1);
    }
    mlx_image_to_window(mlx->id, mlx->cub->bigmap, 0, 0);
    mlx_image_to_window(mlx->id, mlx->cub->minimap, 0,  WIDTH - ((WIDTH / 3) / MINIMAP) * MINIMAP);
}

void convert_tex_to_img(t_mlx *mlx)
{
    mlx->cub->south_image = mlx_texture_to_image(mlx, mlx->cub->south_tex);
    mlx->cub->north_image = mlx_texture_to_image(mlx, mlx->cub->north_tex);
    mlx->cub->east_image = mlx_texture_to_image(mlx, mlx->cub->east_tex);
    mlx->cub->west_image = mlx_texture_to_image(mlx, mlx->cub->west_tex);
    
}