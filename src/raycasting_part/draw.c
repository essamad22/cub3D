/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:16:22 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/29 20:57:40 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void ft_player(int x, int y, t_data *img)
{
    int i;
    int j;

    i = x - 4;
    j = 0;
    while (j <= 8)
    {
        i = x - 4;
        while (i <= x + 4)
        {
            my_mlx_pixel_put(img, i, y + j - 4, 0x00FF0000);
            i++;
        }
        j++;
    }
}

void draw_wall(t_draw wall, t_data *img, t_ray ray, t_par *par)
{
    t_tex *tex;
    int    i;
    int    x_offset;
    int    y_offset;
    float  distortion;

    (void)ray;
    (void)img;
    i = wall.y;
    tex = get_tex(ray.dir, par);
    x_offset = (int)(ray.x_hit + ray.y_hit) % TILE_SIZE;
    while (i <= wall.wall_height + wall.y)
    {
        distortion = i - (HEIGHT - wall.height) / 2.0;
        y_offset = (int)(distortion * (float)tex->height / wall.height);
        my_mlx_pixel_put(img, wall.x, i, get_pixel(tex->img, x_offset, y_offset, tex));
        i++;
    }
}

void draw_ceiling(t_data *img, int x, int y, int color)
{
    int i;

    i = 0;
    while (i < y)
    {
        my_mlx_pixel_put(img, x, i, color);
        i++;
    }
}

void draw_floor(t_data *img, int x, int y, int color)
{
    int i;

    i = y;
    while (i < HEIGHT)
    {
        my_mlx_pixel_put(img, x, i, color);
        i++;
    }
}
// void draw_line(t_data *img, t_par *par, int x2, int y2)
// {
//     int dx = x2 - (par->player->posX / 8);
//     int dy = y2 - (par->player->posY / 8);
//     float steps, k;
//     float xIncrement, yIncrement, x = par->player->posX / 8, y = par->player->posY / 8;
//
//     if (abs(dx) > abs(dy))
//         steps = abs(dx);
//     else
//         steps = abs(dy);
//     xIncrement = dx / (float)steps;
//     yIncrement = dy / (float)steps;
//     k = 0;
//     while (k < steps)
//     {
//         // if (y <= 0 || x <= 0 || y > par->height * 16 || x > par->width * 16)
//         //     break;
//         if (par->map[(int)(y / 8)][(int)(x / 8)] == '1')
//             break;
//         my_mlx_pixel_put(img, x, y, 0x00FF0000);
//         x += xIncrement;
//         y += yIncrement;
//         k++;
//     }
//
// }
// void stroke(t_data *img, t_par *par)
// {
//     int x = par->player->posX / 8;
//     int y = par->player->posY / 8;
//     float angle = norm_angle(par->player->rotAngle);
//     int i = 0;
//
//     while (i < 1)
//     {
//         x += (cos(angle) * 50);
//         y += (sin(angle) * 50);
//
//         draw_line(img, par, x, y);
//         i++;
//     }
// }
//
