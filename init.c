/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:43:08 by derblang          #+#    #+#             */
/*   Updated: 2023/12/12 14:22:02 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init(t_cub *cub)
{
    cub->map = NULL;
    cub->horizontale = 0;
    cub->verticale = 0;
    cub->floor_color = NULL;
    cub->ceilling_color = NULL;
    cub->pathEast = NULL;
    cub->pathNorth = NULL;
    cub->pathWest = NULL;
    cub->pathSouth =NULL;
}



