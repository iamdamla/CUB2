/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:11 by derblang          #+#    #+#             */
/*   Updated: 2023/12/14 12:49:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static char	*subjoin(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
// 	{
// 		i++;
// 	}
// 	return (ft_strjoin(str + i, ""));
// }


void texture_path(char *line, t_cub *cub)
{
    int len;
    len = ft_strlen(line - 1);
    printf("len -> %d\n", len);
    
    if(line[2] == ' ')
    {
        if(line[0] == 'N' && line[1] == 'O')
            cub->pathNorth = ft_strdup(line + 3);
        printf("pathNorth----> %s\n", cub->pathNorth);
            
    }
    // if(find_start_of_str(line, "NO") == 1)
    // {
    //     if(cub->pathNorth == NULL)
    //         cub->pathNorth = line;
    //     printf("pathNorth--->  %s\n", cub->pathNorth);
              
    // }
    // else
    //     printf("Ne oluyor\n");
}


int get_texture(char *line, t_cub *cub)
{
    char *path;
    int i = 3;
    while(*line)
        line++;
    printf("line -> %s\n", line);
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
           
            texture_path(path, cub);
            return 0;
        }
    }
    return -1;
}