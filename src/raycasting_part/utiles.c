/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:00:48 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 16:43:15 by aakhtab          ###   ########.fr       */
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

unsigned int get_pixel(t_data *img, int x, int y, t_tex *tex)
{
    char *dst;

    if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
        return (0);
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
        return ;
    }
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
