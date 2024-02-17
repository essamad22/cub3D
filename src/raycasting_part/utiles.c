/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:00:48 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/17 18:47:08 by aakhtab          ###   ########.fr       */
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
    printf("size of map\n");
    while (map[i])
        i++;
    while (map[0][j])
        j++;
    *x = j * 32;
    *y = i * 32;
}

void draw_square(void *mlx, void *win, int x, int y, unsigned int color)
{
    int i;
    int j;

    i = 0;
    while (i < 32)
    {
        j = 0;
        while (j < 32)
        {
            if (i == 0 || j == 0)
                mlx_pixel_put(mlx, win, x * 32 + j, y * 32 + i, 0x00A000D7);
            else
                mlx_pixel_put(mlx, win, x * 32 + j, y * 32 + i, color);
            j++;
        }
        i++;
    }
}
