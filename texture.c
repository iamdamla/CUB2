/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:11 by derblang          #+#    #+#             */
/*   Updated: 2023/12/14 14:22:04 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// void texture_path(char *line, t_cub *cub)
// {
//     while(*line)
//         line++;
//     printf("%d\n", line[2]);
    
//     if(line[2] == ' ')
//     {
//         if(line[0] == 'N' && line[1] == 'O')
//             cub->pathNorth = ft_strdup(line + 3);
//         printf("pathNorth 1----> %s\n", cub->pathNorth);  
//     }
 
// }


int get_texture(char *line)
{
    char *path;
    int i = 3;
    while(line[i])
    {
        if(line[i] == ' ')
            ++i;
        else if(ft_isascii(line[i]))
        {
            path = malloc(sizeof(char) * (ft_strlen(line + i) + 1));
            if(!path)
                return -1;
            ft_strcpy(path, line + i);
            printf("path---> %s\n", path);
            if(!ft_strstr(path, ".png"))
            {
                free(path);
                return(printf("Texture doesnt end with a good extention!\n"));
            }
           
            return 0;
        }
    }
    return -1;
}