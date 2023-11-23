/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:43:08 by derblang          #+#    #+#             */
/*   Updated: 2023/11/23 12:57:02 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init(t_cub *cub)
{
    cub->map = NULL;
    cub->horizontale = 0;
    cub->verticale = 0;
    cub->floor_color = NULL;
    cub->ceiling_color = NULL;
}

void color_init(t_color *color)
{
    color->r = 0;
    color->g = 0;
    color->b = 0;
    color->a = 0;

}

