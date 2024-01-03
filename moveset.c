/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:37:19 by derblang          #+#    #+#             */
/*   Updated: 2024/01/03 11:40:13 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_down(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_S))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x,mlx->player->pixel_coord.y + 5))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.y += 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}

void move_up(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_W))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x,mlx->player->pixel_coord.y - 5))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.y -= 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}

void move_right(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_D))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x + 5,mlx->player->pixel_coord.y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.x += 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}

void move_left(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_A))
    {
        if(!is_wall(mlx,mlx->player->pixel_coord.x - 5,mlx->player->pixel_coord.y))
        {
            delete_character(mlx);
            delete_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
            mlx->player->pixel_coord.x -= 5;
            draw_character(mlx);
            draw_beam(mlx, mlx->player->pixel_coord.x,mlx->player->pixel_coord.y);
        }
    }
}