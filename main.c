/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2023/11/29 13:34:10 by derblang         ###   ########.fr       */
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
//}

int main(int argc, char **argv)
{
    t_cub cub;

    check_args(argc);
    check_file_extension(argv[1]);
    cub.map = read_map(argv[1]);
    if(cub.map != NULL)
        print_arr(cub.map);
    else
        ft_puterror("Error: There is a map issue!");
    check_wall(cub.map);
    //find_dim(cub.map, &cub);
    // printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
    // begin = find_start(cub.map);
    // printf("\nx : %d\ny : %d\n",begin.x,begin.y);
    // flood_fill(cub.map,begin,cub.horizontale,cub.verticale);

    
   // char *validColor[] = {"255,0,0", "0,255,0", "0,0,255", NULL}; //Valid
   //char *invalidCharColor[] = {"255,0,0", "0,abc,0", "0,0,255", NULL}; //Invalid char
    // char *missingCharColor[] = {"255,0,0", "0,255,0", NULL}; //Missing char
    // check_color_arr(missingCharColor);
    // check_color_arr(invalidCharColor);
    //check_color_arr(validColor);
//     char color1[] = "F 255,128,0";
//     int res1 = get_color(color1, &cub, 0);
//    if(res1 == 0)
//         printf("Success\n");
//     else
//         printf("Error Color\n");

//     char color2[] = "F 255,128";
//     int res2 = get_color(color2, &cub, 0);
//    if(res2 == -1)
//         printf("Invalid color format\n");
//     else
//         printf("Some error\n");

    cub.map = get_map(cub.map);
    if(cub.map == NULL)
        printf("WTF\n"); 
     
    //free_arr(cub.map);
  
    return 0;
}