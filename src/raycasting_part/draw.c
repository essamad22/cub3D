/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:16:22 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/28 21:24:14 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void draw_line(t_data *img, t_par *par, int x2, int y2)
{
    int dx = x2 - (par->player->posX / 4);
    int dy = y2 - (par->player->posY / 4);
    float steps, k;
    float xIncrement, yIncrement, x = par->player->posX / 4, y = par->player->posY / 4;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;
    k = 0;
    while (k < steps)
    {
        // if (y <= 0 || x <= 0 || y > par->height * 16 || x > par->width * 16)
        //     break;
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
    int x = par->player->posX / 4;
    int y = par->player->posY / 4;
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

