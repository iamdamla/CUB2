/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2023/12/14 10:48:15 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void find_dim(char **map,t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    cub->verticale = count_line(map);
    while(map[i])
    {
        while(map[i][j])
            j++;
        if(cub->horizontale < j)
            cub->horizontale = j;
        i++;
        j = 0;
    }
    if(cub->horizontale == 0 && cub->verticale == 0)
        ft_puterror("map is empty");
}


int main(int argc, char **argv)
{
    //t_mlx mlx;
    t_player player;
    t_cub cub;
    
    init(&cub);
    check_args(argc);
	check_file_extension(argv[1]);
    cub = check_all_map(argv[1]);
     if(cub.map == NULL)
        printf("Map cant be read!\n");
     if(cub.map != NULL)
      {
        print_arr(cub.map);
      }
      //get_color(argv[1], &cub); 
   
    find_pos(cub.map, &player);
    //mlx.player = &player;
   
     find_dim(cub.map, &cub);
    //printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
    flood_fill(cub.map,cub.horizontale,cub.verticale);
    //open_window(&mlx, &cub, &player);
    free_arr(cub.map);
     //free_only_cub(&cub);
 }

