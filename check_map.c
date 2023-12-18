/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:21:49 by derblang          #+#    #+#             */
/*   Updated: 2023/12/18 13:46:46 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void invalid_char(char c, size_t *count)
{
    if(c != 'N' && c != 'E' && c != 'S' && c != 'W' && c != '0' && c!= '1'
        && c != ' ')
            ++*count;
}

int invalid_char_check(char **map)
{
    int i = -1;
    size_t count  = 0;
    int j;
    while(map[++i])
    {
        j = -1;
        while(map[i][++j])
            invalid_char(map[i][j], &count);
    }
    if(count != 0)
    {
        printf("Invalid char in the map!\n");
        return (-1);
    }
    else
        return 0;
}
static int nb_of_player(char **map)
{
    int i = -1;
    int j = 0;
    int count = 0;
    while(map[++i])
    {
        j = -1;
        while(map[i][++j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                ++count;
        }
    }
    if(count != 1)
    {
        printf("Invalid number of player!\n");
        return -1;
    }
    return 0;
}
int check_map_components(char **map)
{
    if(nb_of_player(map) == -1 || invalid_char_check(map) == -1)
        return -1;
    check_wall(map);
    return 0;
}