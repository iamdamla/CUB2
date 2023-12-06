/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:00 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static void find_dim(char **map,t_cub *cub)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     cub->verticale = count_line(map);
//     while(map[i])
//     {
//         while(map[i][j])
//             j++;
//         if(cub->horizontale < j)
//             cub->horizontale = j;
//         i++;
//         j = 0;
//     }
//     if(cub->horizontale == 0 && cub->verticale == 0)
//         ft_puterror("map is empty");
// }

int main(int argc, char **argv)
{
    t_cub cub;
    t_player player;

    check_args(argc);
    check_file_extension(argv[1]);
    cub.map = read_map(argv[1], &cub);
    check_map(cub.map);
    check_wall(cub.map);
    find_pos(cub.map,&player);
    if(cub.map != NULL)
        print_arr(cub.map);
    printf("\n");
    print_arr(cub.map);
    free_arr(cub.map);
    
  
  
    return 0;
}

// int main(int argc, char **argv)
// {
//     t_cub cub;
//     t_player player;

//     check_args(argc);
//     check_file_extension(argv[1]);
//     cub.map = read_map(argv[1], &cub);
//     check_map(cub.map);
//     find_pos(cub.map,&player);
//     if(cub.map != NULL)
//         print_arr(cub.map);
//      //find_dim(cub.map, &cub);
//         // printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
//     //check_wall(cub.map);
//     //check_map(cub.map);
    
//     //parse_floor(&cub);
//     //flood_fill(cub.map,cub.horizontale,cub.verticale);
//     printf("\n");
//     print_arr(cub.map);
//     free_arr(cub.map);
    
//    // char *validColor[] = {"255,0,0", "0,255,0", "0,0,255", NULL}; //Valid
//    //char *invalidCharColor[] = {"255,0,0", "0,abc,0", "0,0,255", NULL}; //Invalid char
//     // char *missingCharColor[] = {"255,0,0", "0,255,0", NULL}; //Missing char
//     // check_color_arr(missingCharColor);
//     // check_color_arr(invalidCharColor);
//     //check_color_arr(validColor);
  
//     return 0;
// }