/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:27:28 by derblang          #+#    #+#             */
/*   Updated: 2023/11/21 14:08:35 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **read_map(char *file)
{
    int fd;
    char **arr;
    char *buf;
    char *temp;
    fd = ft_open_fd(file);
    buf = malloc(sizeof(char) * 1);
    if(!buf)
        return (NULL);
    buf[0] = '\0';
    temp = buf;
    while(1)
    {
        temp = get_next_line(fd);
        if(temp == NULL)
            break;
        buf = ft_strjoin(buf, temp);
        free(temp);
    }
    arr = ft_split(buf, '\n');
    free(buf);
    close(fd);
    return (arr);
}



int	map_is_closed(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'S'
				|| map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E')
			{
                // Check the number of surrounding characters
                count = check_sides_of_map(map, i, j, count);
                printf("Character: %c, Position: (%d, %d), Count: %d\n", map[i][j], i, j, count);
				if (count != 4)
                {
                    printf("Count is not 4\n");
                    return 1;
                }
			}
		}
		j = -1;
	}
	return (0);
}

int valid_map(char **map)
{
    if(map_is_closed(map))
        return (printf("Check Walls: Map is not closed!\n"));

    return 0;
}




