/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:00:48 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/27 05:08:10 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void size_of_map(char **map, int *x, int *y)
{
    //check size of map for the window size
    int i;
    int j;

    i = 0;
    j = 0;
    // printf("size of map\n");
    while (map[i])
        i++;
    while (map[0][j])
        j++;
    *x = j;
    *y = i;
}

void draw_square(t_data *img, int x, int y, unsigned int color)
{
    int i;
    int j;

    i = 0;
    while (i < 16)
    {
        j = 0;
        while (j < 16)
        {
            if (i == 0 || j == 0)
                my_mlx_pixel_put(img, x * 16 + j, y * 16 + i, 0x000000);
            else
                my_mlx_pixel_put(img, x * 16 + j, y * 16 + i, color);
            j++;
        }
        i++;
    }
}

int check_wall(float x, float y, char **map)
{
    float	grid_x;
	float	grid_y;

    int height;
    int width;
	grid_x = x / TILE_SIZE;
	grid_y = y / TILE_SIZE;
    size_of_map(map, &width, &height);
	if (grid_y >= (height) || grid_y < 0
		|| grid_x >= (width) || grid_x < 0)
		return (1);
    if (map[(int)grid_y][(int)grid_x] == '1')
        return (1);
    return (0);
}
