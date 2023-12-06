/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:42:31 by derblang          #+#    #+#             */
/*   Updated: 2023/12/06 13:47:32 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int color_range(t_cub *cub)
{
    if(cub->r <= 255 && cub->r >= 0)
        return 1;
    if(cub->g <= 255 && cub->g >= 0)
        return 1;
    if(cub->b <= 255 && cub->b >= 0)
        return 1;
    return 0;
}

//Check if there is another char or space in the rgb
void check_color_arr(char **arr)
{
    int i;
    int j;

    i = -1;
    j = -1;
    
    while(arr[++i])
    {
        while(arr[i][++j])
        {
            if(ft_isalpha(arr[i][j]) || ft_isspace(arr[i][j]))
            {
                ft_puterror("Error\nWrong character in the color\n");
                exit(0);
            }
        }
        j = -1;
    }
    if(i < 3)
        ft_puterror("Missing character in the color\n");
}
void	convert_rgb(char *line, t_cub *cub, char c)
{	
	char	**colors;
    (void)c;
	int		i;

	i = 0;
	while (!ft_isdigit(*line))
		line++;
	colors = ft_split(line, ',');
    printf("Colors: %s, %s, %s\n", colors[0], colors[1], colors[2]);
    int j = 0;
    while(colors[j])
        printf("Print---> %s\n", colors[j++]);
	
    check_color_arr(colors);
	cub->r = ft_atoi(colors[0]);
	cub->g = ft_atoi(colors[1]);
	cub->b = ft_atoi(colors[2]);
	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
}

void get_color(char *line, t_cub *cub)
{
    int i = 0;
    while(line[i] && ft_isspace(line[i]))
        i++;
    if(line[i] != 'F' && line[i] != 'C')     
        ft_puterror("Wrong color code\n");
    if(line[i] == 'C')
        convert_rgb(line, cub, 'C');
    else if(line[i] == 'F')
        convert_rgb(line, cub, 'F');
}



void check_color(t_cub *cub)
{
    char **colors;
    colors = ft_split(cub->floor_color, ',');
    // int j = 0;
    // while(colors[j])
    //     printf("Print---> %s\n", colors[j++]);
    // printf("Colors: %s, %s, %s\n", colors[0], colors[1], colors[2]);
    cub->floor[0] = ft_atoi(colors[0]);
    cub->floor[1] = ft_atoi(colors[1]);
    cub->floor[2] = ft_atoi(colors[2]);
    free_arr(colors);
    
//    colors = ft_split(cub->ceilling_color, ',');
//     cub->ceilling[0] = ft_atoi(colors[0]);
//     cub->ceilling[1] = ft_atoi(colors[0]);
//     cub->ceilling[2] = ft_atoi(colors[0]);
//    free_arr(colors);
}




