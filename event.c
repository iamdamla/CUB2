/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:59:11 by derblang          #+#    #+#             */
/*   Updated: 2023/12/11 12:59:14 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void event(mlx_key_data_t event,void *content)
{
    t_mlx *mlx;

    (void)event;
    mlx = content;
    if(mlx_is_key_down(mlx->id, MLX_KEY_ESCAPE))
    {
        mlx_close_window(mlx->id);
    }
}

void update_player_position(void *param)
{
    t_mlx *mlx;
    
    mlx = param;
    if(mlx_is_key_down(mlx->id, MLX_KEY_S))
    {
        mlx->player->position.x += 1;
        draw_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
    }
}