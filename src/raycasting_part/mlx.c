/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:09:51 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/28 21:01:13 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_player(int x, int y, t_data *img)
{
    int i;
    int j;
    int des;

    i = 2;
    j = 0;
    des = 1 - i;
    while (i >= j)
    {
        my_mlx_pixel_put(img, (x) + i, (y) + j, 0x00000000);
        my_mlx_pixel_put(img, (x) - i, (y) + j, 0x00000000);
        my_mlx_pixel_put(img, (x) + i, (y) - j, 0x00000000);
        my_mlx_pixel_put(img, (x) - i, (y) - j, 0x00000000);
        my_mlx_pixel_put(img, (x) + j, (y) + i, 0x00000000);
        my_mlx_pixel_put(img, (x ) - j, (y) + i, 0x00000000);
        my_mlx_pixel_put(img, (x ) + j, (y) - i, 0x00000000);
        my_mlx_pixel_put(img, (x ) - j, (y) - i, 0x00000000);
        j++;
        if (des <= 0)
            des += 2 * j + 1;
        else
        {
            i--;
            des += 2 * (j - i) + 1;
        }
    }
}

void	loop(t_data *img, t_par *par)
{
	int	x;
	int	y;

	y = 0;
	while (y < par->height)
	{
        x = 0;
		while (x < par->width)
		{
			if (par->map[y][x] == '1')
				draw_square(img, x, y, 0x000000);
			else
				draw_square(img, x, y, 0xfafafa);
			x++;
		}
		y++;
        // render(par);
	}
    if (par->player->posX / 4 < par->width * 16 && par->player->posY / 4 < par->height * 16)
        ft_player(((par->player->posX) / 4), (par->player->posY / 4), img);
    // ft_player(((par->player->posX) / 2), (par->player->posY / 2), img);
    stroke(img, par);
}

int update(t_par *par)
{
    int c;

    c = 0;
    par->mov_step = par->player->walkDir * mov_speed;
    par->player->rotAngle += par->player->turnDir * rot_speed;
    par->player->dirX = cos(par->player->rotAngle) * par->mov_step;
    par->player->dirY = sin(par->player->rotAngle) * par->mov_step;
    if (par->player->walkDir || par->player->turnDir)
    {
        c += update_player(par);
    }
    if (par->player->turnDir || c)
    {
        par->player->rotAngle = norm_angle(par->player->rotAngle);
        // loop(par->map, par->mlx->mlx_p, par->mlx->win_p, par);
        render(par);
    }
    return (0);
}

int close_win(t_par *par)
{
    mlx_destroy_image(par->mlx->mlx_p, par->mlx->data.img);
    mlx_destroy_window(par->mlx->mlx_p, par->mlx->win_p);
    free_tex(par->tex);
    free(par);
    exit(0);
    return (0);
}

int key_up(int key, t_par *par)
{
    if (key == 1493 || key == 119 || key == ARROW_UP_L)
        par->player->walkDir = 0;
    if (key == 1491 || key == 115 || key == ARROW_DOWN_L)
        par->player->walkDir = 0;
    if (key == 1492 || key == 97 || key == ARROW_LEFT_L)
        par->player->turnDir = 0;
    if (key == 1514 || key == 100 || key == ARROW_RIGHT_L)
        par->player->turnDir = 0;
    return (0);
}

int	key_down(int key, t_par *par)
{
    if (key == 65307)
    {
        close_win(par);
    }
	if (key == 97 || key == ARROW_LEFT_L || key == 1492)
		par->player->turnDir = -1;
	if (key == 100 || key == ARROW_RIGHT_L || key == 1514)
        par->player->turnDir = 1;
	if (key == 119 || key == ARROW_UP_L || key == 1493)
		par->player->walkDir = 1;
	if (key == 115 || key == ARROW_DOWN_L || key == 1491)
		par->player->walkDir = -1;
	return (0);
}

int	mlx(char **map, void *par1)
{
    t_par *par;
    par = par1;
   
    par->map = map;
    size_of_map(map, &par->width, &par->height);
    par->mlx->mlx_p = mlx_init();
    par->mlx->win_p = mlx_new_window(par->mlx->mlx_p, WIDTH, HEIGHT, "CUB3D");
    par->mlx->data.img = mlx_new_image(par->mlx->mlx_p, WIDTH, HEIGHT);
    par->mlx->data.addr = mlx_get_data_addr(par->mlx->data.img, &par->mlx->data.bits_per_pixel, &par->mlx->data.line_length,
            &par->mlx->data.endian);
    init_tex(par);
    render(par);
    mlx_hook(par->mlx->win_p, 2, 1L<<0, key_down, par);
    mlx_hook(par->mlx->win_p, 3, 1L << 1, key_up, par);
    mlx_hook(par->mlx->win_p, 17, 1L<<17, close_win, par);
    mlx_loop_hook(par->mlx->mlx_p, update, par);
    mlx_loop(par->mlx->mlx_p);
    return (0);
}
