/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:27:28 by derblang          #+#    #+#             */
/*   Updated: 2023/12/06 13:45:28 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char *read_file_lines(int fd, t_cub *cub) 
{
    char *buf;
    char *temp;
    char *newbuf;

    buf = malloc(sizeof(char));
    if (!buf)
        return NULL;
    buf[0] = '\0';
    while (1) 
    {
        temp = get_next_line(fd);
        if (temp == NULL)
            break;
        get_color(temp, cub);
        free(temp);
        newbuf = ft_strjoin(buf, temp);
        //free(temp);
        free(buf);
        buf = newbuf;
    }
    return buf;
}

char **read_map(char *file, t_cub *cub)
{
    int fd;
    char **arr;
    char *buf;

   
    if((fd = ft_open_fd(file)) < 0)
        return NULL;
    buf = read_file_lines(fd, cub);
    if(buf == NULL)
    {
        printf("Buf is NULL\n");
        return(NULL);
    }    
    
    arr = ft_split(buf, '\n');
    free(buf);
    close(fd);
    return (arr);
}



static int ft_count(char **map,int i,int j)
{
    static int k;

    if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
        k++;
    if(map[i][j] == 'C' || map[i][j] == 'F' ||
            (map[i][j] == 'N' && map[i][j + 1] == 'O' ))
        k++;
    return(k);
}



void check_map(char **map)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            k = ft_count(map,i,j);
            if(map[i][j] != '1' && map[i][j] != '0' &&
                map[i][j] != 'N' && map[i][j] != 'S' &&
                map[i][j] != 'E' && map[i][j] != 'W' &&
                map[i][j] != ' ')
                printf("Error\nParsing incorrect %c\n",map[i][j]);
            j++;
        }
        i++;
        j = 0;
    }
    if(k < 1 || k > 1)
        ft_puterror("Problem with count number");
}

void find_pos(char **map,t_player *player)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' 
                || map[i][j] == 'W')
            {
                player->position.x = i;
                player->position.y = j;
            }
            if(map[i][j] == 'N')
                player->direction = M_PI / 4;
            if(map[i][j] == 'E')
                player->direction = 0;
            if(map[i][j] == 'W')
                player->direction = M_PI / 2;
            if(map[i][j] == 'S')
                player->direction = (3 * M_PI) / 4;
            j++;
        }
        i++;
        j = 0;
    }
    //printf("player.x %d\nplayer.y %d\nplayer dir %f\n",player->position.x,player->position.y,player->direction);
}




