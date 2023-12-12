/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:11 by derblang          #+#    #+#             */
/*   Updated: 2023/12/12 14:52:55 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void texture_path(char *line, t_cub *cub)
{
    (void)cub;
  
    if(line[0] == 'N' && line[1] == 'O')
    {
        if(find_start_of_str(line, "NO") == 1)
        {
            if(cub->pathNorth == NULL)
                cub->pathNorth = ft_strcpy(line + 3);
            else
            {
                free_cub(cub);
                printf("There is an error somewhere");
            }
              
        }
    }
}

int get_texture(char *line, t_cub *cub)
{
      char *path;
      (void)cub;
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