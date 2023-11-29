/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:42:31 by derblang          #+#    #+#             */
/*   Updated: 2023/11/29 11:20:33 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int color_return(char **colors, int ret)
{
    free_arr(colors);
    return (ret);
}
static t_color color_rgba(char **colors)
{
    t_color rgba;

    rgba.r = ft_atoi(colors[0]);
    rgba.g = ft_atoi(colors[1]);
    rgba.b = ft_atoi(colors[2]);
    rgba.a = 255;
    return rgba;
}

static int valid_color(t_color color)
{
    if(color.r <= 255 && color.r >= 0 && color.g <= 255 && color.g >= 0
        && color.b <= 255 && color.b >= 0)
        return (1);
    return (0);
}

static void get_color_mode(int mode, t_color rgba, t_cub *cub)
{
    if(mode == 0)
        cub->floor_color = rgba;
    else if(mode == 1)
        cub->ceiling_color = rgba;
}
//Check if there is another char or space in the rgb
static int check_color_arr(char **colors, int j)
{
    int i;

    
    while(colors[++j])
    {
        i = -1;
        while(colors[j][++i])
        {
            if(ft_isdigit(colors[j][i]) != 1)
                return 1;
        }
    }
    return 0;

}

int get_color(char *str, t_cub *cub, int mode)
{
    t_getcolor c;

    c.i = 2;
    c.j = -1;
    while(str[c.i])
    {
        //skip whitespaces
        if(str[c.i] == ' ')
            ++c.i;
        else if(ft_isascii(str[c.i]) == 1)
        {
            c.colors = ft_split(str + c.i, ',');
            // Check if there are exactly 3 components in the color
            if(ft_arrlen(c.colors) != 3)
                return (color_return(c.colors, -1));
            // Check if the color components are valid integers
            if (check_color_arr(c.colors, c.j))
                return (color_return(c.colors, -1));
            // Convert the color components to an RGBA structure
            c.rgba = color_rgba(c.colors);
            // Check if the color components are within the valid range (0-255)
            if(valid_color(c.rgba))
                return (color_return(c.colors, -1));
            // Update the color in the t_cub structure based on the specified mode
            get_color_mode(mode, c.rgba, cub);
            return (color_return(c.colors, 0));
        }
        else
            return -1;
    }
    return -1;
}



