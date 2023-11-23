/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:42:31 by derblang          #+#    #+#             */
/*   Updated: 2023/11/23 13:48:20 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static t_color color_rgb(char **colors)
// {
//     t_color rgba;

//     rgba.r = ft_atoi(colors[0]);
//     rgba.g = ft_atoi(colors[1]);
//     rgba.b = ft_atoi(colors[2]);
//     rgba.a = 255;
//     return rgba;
// }

// static int valid_color(t_color color)
// {
//     if(color.r <= 255 && color.r >= 0 && color.g <= 255 && color.g >= 0
//         && color.b <= 255 && color.b >= 0)
//         return (1);
//     return (0);
// }

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

