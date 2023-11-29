/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:21:49 by derblang          #+#    #+#             */
/*   Updated: 2023/11/29 13:30:49 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void check_map_char(char *map, int *count, char *str)
{
    if(str[2] == '\0') //NO SO..
    {
        if(map[0] == str[0] && map[1] == str[1])
            ++*count;
    }
    else
    {
        if(map[0] == str[0] && map[1] == str[1] && map[2] == str[2])
            ++*count;
    }
}

static void check_map_batch(char *map, int *count)
{
    check_map_char(map, count, "NO ");
    check_map_char(map, count, "SO ");
    check_map_char(map, count, "WE ");
    check_map_char(map, count, "EA ");
    check_map_char(map, count, "F \0");
    check_map_char(map, count, "C \0");
}

char **get_map(char **map)
{
    int i = -1;
    int count = 0;
    while(map[++i])
    {
        check_map_batch(map[i], &count);
        if(count == 1)
            printf("11111\n");
    }
    return NULL;
}