/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:57:29 by derblang          #+#    #+#             */
/*   Updated: 2023/11/21 15:04:04 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_around(char **map, int i, size_t j)
{
	if (map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' '
		&& map[i][j - 1] != '\n')
		return (-1);
	else if (map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != ' '
			&& map[i][j + 1] != '\n')
		return (-1);
	else if (map[i + 1] && j <= ft_strlen(map[i + 1]) && map[i + 1][j] != '1'
			&& map[i + 1][j] != ' ' && map[i + 1][j] != '\n')
		return (-1);
	else if (i > 1 && map[i - 1] && j <= ft_strlen(map[i - 1]) && map[i
			- 1][j] != '1' && map[i - 1][j] != ' ' && map[i - 1][j] != '\n')
		return (-1);
	return (0);
}

int	check_closed_around_space(char **map)
{
	int		i;
	int		count;
	size_t	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j] && map[i][j + 1])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
				count++;
			if (map[i][j] == ' ')
			{
                if (check_around(map, i, j) == -1)
					return (printf("Error \nInvalid map: map is not closed\n"));
            }	
			j++;
		}
		i++;
	}
	if (count == 0 || count > 1)
		return (printf("Error \nInvalid map: wrong player number\n"));
	return (0);
}

int valid_map(char **map)
{
    if(check_closed_around_space(map))
        return (printf("Check Walls: Space's are not closed!\n"));
    return 0;
}

