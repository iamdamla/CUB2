/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:14:49 by derblang          #+#    #+#             */
/*   Updated: 2023/12/12 14:19:22 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int find_start_of_str(char *str, char *prefix)
{
    while(*prefix)
    {
        if(*prefix != *str)
            return 0;
        prefix++;
        str++;
    }
    return 1;
}