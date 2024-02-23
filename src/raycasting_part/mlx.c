/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:09:51 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/23 05:56:14 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_player(int x, int y, void *mlx, void *win)
{
    int i;
    int j;
    int des;

    i = 2;
    j = 0;
    des = 1 - i;
    while (i >= j)
    {
        mlx_pixel_put(mlx, win, (x + 32 / 2) + i, (y + 32/2) + j, 0x00000000);
        mlx_pixel_put(mlx, win, (x + 32 / 2) - i, (y + 32/2) + j, 0x00000000);
        mlx_pixel_put(mlx, win, (x + 32 / 2) + i, (y + 32/2) - j, 0x00000000);
        mlx_pixel_put(mlx, win, (x + 32 / 2) - i, (y + 32/2) - j, 0x00000000);
        mlx_pixel_put(mlx, win, (x + 32 / 2) + j, (y + 32/2) + i, 0x00000000);
        mlx_pixel_put(mlx, win, (x + 32 / 2) - j, (y + 32/2) + i, 0x00000000);
        mlx_pixel_put(mlx, win, (x + 32 / 2) + j, (y + 32/2) - i, 0x00000000);
        mlx_pixel_put(mlx, win, (x + 32 / 2) - j, (y + 32/2) - i, 0x00000000);
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

void	loop(char **map, void *mlx, void *win, t_par *par)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(mlx, win, x, y, 0xAAA000D7);
			else
				draw_square(mlx, win, x, y, 0x10FFFFFF);
			x++;
		}
		y++;
		ft_player(par->player->posX, par->player->posY, mlx, win);
        stroke(mlx, win, par);
	}
}

int update(t_par *par)
{
    if (par->player->turnDir != 0)
    {
        par->player->rotAngle += par->player->turnDir * rot_speed;
        loop(par->map, par->mlx, par->win, par);
        printf("rotAngle = %f\n", par->player->rotAngle);
        printf("turnDir = %f\n", par->player->turnDir);
    }
    return (0);
}
// void	ft_rotate_with_dir(t_par *par, float rot_dir)
// {
// 	t_player	*p;
// 	// float		tmp_x;
//
// 	p = par->player;
//     p->rotAngle += rot_dir;
	// tmp_x = p->dirX;
 //    printf("dirX = %f\n", p->dirX);
	// p->dirX = p->dirX * cos(rot_dir) - p->dirY * sin(rot_dir);
	// p->dirY = tmp_x * sin(rot_dir) + p->dirY * cos(rot_dir);
	// tmp_x = p->planX;
	// p->planX = p->planX * cos(rot_dir) - p->planY * sin(rot_dir);
	// p->planY = tmp_x * sin(rot_dir) + p->planY * cos(rot_dir);
// }

void	ft_rotate_player(t_par *par, int key)
{
	float	rot_dir;

    rot_dir = 0;
	if (key == 65361 || key == 97 || key == 1492)
	{
		printf("LEFT \n");
		rot_dir = -1;
	}
	else if (key == 65363 || key == 100 || key == 1514)
	{
		printf("RIGHT\n");
		rot_dir = 1;
	}
    printf("rotAngle = %f\n", par->player->rotAngle);
	par->player->rotAngle += rot_dir * rot_speed;
    printf("rotAngle = %f\n", par->player->rotAngle);
	// ft_rotate_with_dir(par, rot_dir);
}

int close_win(t_par *par)
{
    mlx_destroy_image(par->mlx, par->img.img);
    mlx_destroy_window(par->mlx, par->win);
    exit(0);
    return (0);
}

int key_up(int key, t_par *par)
{
    if (key == 1493 || key == 119)
        par->player->walkDir = 0;
    if (key == 1491 || key == 115)
        par->player->walkDir = 0;
    if (key == 1492 || key == 97)
        par->player->turnDir = 0;
    if (key == 1514 || key == 100)
        par->player->turnDir = 0;
    return (0);
}

int	key_down(int key, t_par *par)
{
    if (key == 65307)
    {
        mlx_destroy_window(par->mlx, par->win);
        exit(0);
    }
	// if (key == 65361 || key == 65363 || key == 97 || key == 100
 //            || key == 1492 || key == 1514)
	// 	ft_rotate_player(par, key);
	if (key == 119 || key == ARROW_UP_L || key == 1493)
		par->player->walkDir = 1;
	if (key == 115 || key == ARROW_DOWN_L || key == 1491)
		par->player->walkDir = -1;
	if (key == 97 || key == ARROW_LEFT_L || key == 1492)
		par->player->turnDir = -1;
	if (key == 100 || key == ARROW_RIGHT_L || key == 1514)
        par->player->turnDir = 1;
	return (0);
}

int	mlx(char **map, void *par1)
{
	// t_data	img;
	t_par	*par;
    int     size[2];

	par = par1;
    size_of_map(map, &size[0], &size[1]);
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, size[0], size[1], "CUB3D");
	par->img.img = mlx_new_image(par->mlx, size[0], size[1]);
	par->img.addr = mlx_get_data_addr(par->img.img, &par->img.bits_per_pixel, &par->img.line_length,
			&par->img.endian);
	loop(map, par->mlx, par->win, par);
    // render(par);
    mlx_hook(par->win, 3, 1L<<1, key_up, par);
	mlx_hook(par->win, 2, 1L<<0, key_down, par);
    mlx_hook(par->win, 17, 1L<<17, close_win, par);
    mlx_loop_hook(par->mlx, update, par);
	mlx_loop(par->mlx);
    return (0);
}
