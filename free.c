/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:41:24 by derblang          #+#    #+#             */
/*   Updated: 2023/12/12 11:45:27 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void free_cub(t_cub *cub)
{
    if(cub->ceilling_color)
        free(cub->ceilling_color);
     if(cub->floor_color)
        free(cub->floor_color);
}

void free_only_cub(t_cub *cub)
{
    if(cub)
        free(cub);
    exit(printf("Malloc error\n"));
}