/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:16:22 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/26 10:52:32 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/3d.h"
// #include <cmath>
#include <math.h>



void draw_line(t_data *img, t_par *par, int x2, int y2)
{
    int dx = x2 - (par->player->posX / 2);
    int dy = y2 - (par->player->posY / 2);
    float steps, k;
    float xIncrement, yIncrement, x = par->player->posX / 2, y = par->player->posY / 2;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;
    k = 0;
    while (k < steps)
    {
        if (par->map[(int)(y / 16)][(int)(x / 16)] == '1')
            break;
        my_mlx_pixel_put(img, x, y, 0x00FF0000);
        x += xIncrement;
        y += yIncrement;
        k++;
    }

}
void stroke(t_data *img, t_par *par)
{
    int x = par->player->posX / 2;
    int y = par->player->posY / 2;
    float angle = norm_angle(par->player->rotAngle);
    int i = 0;

    while (i < 1)
    {
        x += (cos(angle) * 50);
        y += (sin(angle) * 50);

        draw_line(img, par, x, y);
        i++;
    }
}

