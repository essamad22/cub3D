/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:09:51 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/17 18:30:00 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_player(int x, int y, void *mlx, void *win)
{
    mlx_pixel_put(mlx, win, (x + 32 / 2), (y + 32/2), 0x0000FA00);
    mlx_pixel_put(mlx, win, (x + 32 / 2) + 1, (y + 32/2), 0x0000FA00);
    mlx_pixel_put(mlx, win, (x + 32 / 2) - 1, (y + 32/2), 0x0000FA00);
    mlx_pixel_put(mlx, win, (x + 32 / 2), (y + 32/2) + 1, 0x0000FA00);
    mlx_pixel_put(mlx, win, (x + 32 / 2), (y + 32/2) - 1, 0x0000FA00);
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
				draw_square(mlx, win, x, y, 0x00A000D7);
			else
				draw_square(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
		ft_player(par->player->posX, par->player->posY, mlx, win);
	}
}

void	ft_rotate_with_dir(t_par *par, float rot_dir)
{
	t_player	*p;
	float		tmp_x;

	p = par->player;
	tmp_x = p->dirX;
	p->dirX = p->dirX * cos(rot_dir) - p->dirY * sin(rot_dir);
	p->dirY = tmp_x * sin(rot_dir) + p->dirY * cos(rot_dir);
	tmp_x = p->planX;
	p->planX = p->planX * cos(rot_dir) - p->planY * sin(rot_dir);
	p->planY = tmp_x * sin(rot_dir) + p->planY * cos(rot_dir);
}

void	ft_rotate_player(t_par *par, int key)
{
	float	rot_dir;

    rot_dir = 0;
	if (key == 65361 || key == 97 || key == 1492)
	{
		printf("LEFT \n");
		rot_dir = -3.5;
	}
	else if (key == 65363 || key == 100 || key == 1514)
	{
		printf("RIGHT\n");
		rot_dir = 3.5;
	}
	rot_dir *= rot_speed;
	ft_rotate_with_dir(par, rot_dir);
}

int	get_keys(int key, t_par *par)
{
	t_player	*player;

	player = par->player;
    if (key == 65307)
    {
        mlx_destroy_window(par->mlx, par->win);
        exit(0);
    }
	if (key == 65361 || key == 65363 || key == 97 || key == 100
            || key == 1492 || key == 1514)
		ft_rotate_player(par, key);
	if (key == 119 || key == ARROW_UP_L || key == 1493)
		move_forwad(par, player, key);
	if (key == 115 || key == ARROW_DOWN_L || key == 1491)
		move_backward(par, player, key);
	if (key == 97 || key == ARROW_LEFT_L || key == 1492)
		move_left(par, player, key);
	if (key == 100 || key == ARROW_RIGHT_L || key == 1514)
		move_right(par, player, key);
	return (0);
}

int	mlx(char **map, void *par1)
{
	t_data	img;
	t_par	*par;
    int     size[2];

	par = par1;
    size_of_map(map, &size[0], &size[1]);
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, size[0], size[1], "CUB3D");
	img.img = mlx_new_image(par->mlx, size[0], size[1]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
    printf("player x = %f\n", par->player->posX);
    printf("player y = %f\n", par->player->posY);
	loop(map, par->mlx, par->win, par);
	mlx_hook(par->win, 2, 1L<<0, get_keys, par);
	mlx_loop(par->mlx);
    return (0);
}
