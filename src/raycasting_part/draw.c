/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:16:22 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/22 05:34:35 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/3d.h"


void draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float steps, k;
    float xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;
    k = 0;
    while (k < steps)
    {
        mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
        x += xIncrement;
        y += yIncrement;
        k++;
    }

}
void stroke(void *mlx, void *win, t_par *par)
{
    int x = par->player->posX;
    int y = par->player->posY;

    x += (cos(par->player->rotAngle) * 32) + 16;
    y += (sin(par->player->rotAngle) * 32) + 16;

    draw_line(mlx, win, par->player->posX + 16, par->player->posY + 16, x, y);
}

