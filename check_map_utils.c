/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:29:43 by derblang          #+#    #+#             */
/*   Updated: 2023/12/07 13:32:31 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


static void	check_map_char(char *map, int *count, char *str)
{
	if (str[2] == '\0')
	{
		if (map[0] == str[0] && map[1] == str[1])
			++*count;
	}
	else
	{
		if (map[0] == str[0] && map[1] == str[1] && map[2] == str[2])
			++*count;
	}
}


static void	check_map_batch(char *map, int *count)
{
	check_map_char(map, count, "NO ");
	check_map_char(map, count, "SO ");
	check_map_char(map, count, "WE ");
	check_map_char(map, count, "EA ");
	check_map_char(map, count, "FT ");
	check_map_char(map, count, "CT ");
	check_map_char(map, count, "F \0");
	check_map_char(map, count, "C \0");
}

static char	**ft_arrdup(char **arr)
{
	char	**dup;
	int		arr_len;

	dup = NULL;
	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
	if (!arr_len)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!dup)
		return (NULL);
	dup[arr_len] = NULL;
	while (arr_len--)
	{
		dup[arr_len] = ft_strdup(arr[arr_len]);
		if (!dup[arr_len])
		{
			free(dup);
			return (NULL);
		}
	}
	return (dup);
}
static char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (i <= ft_strlen(haystack) - ft_strlen(needle))
	{
		j = 0;
		while (j < ft_strlen(needle))
		{
			if (*(char *)(haystack + i + j) != *(char *)(needle + j))
				break ;
			j++;
		}
		if (j == ft_strlen(needle))
			return (&*(char *)(haystack + i));
		i++;
	}
	return (NULL);
}
char	**get_map_description(char **map)
{
	size_t	i;
	int		count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		check_map_batch(map[i], &count);
		if (count == 6)
		{
			while (map[++i])
			{
				if (map[i][0] == '\n')
					continue ;
				if (ft_strstr(map[i], "1\0"))
					return (ft_arrdup(map + i));
				else
					return (NULL);
			}
		}
	}
	return (NULL);
}