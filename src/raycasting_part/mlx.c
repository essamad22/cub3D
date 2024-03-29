/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:09:51 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 19:00:11 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	loop(t_data *img, t_par *par)
{
	int	x;
	int	y;
	int	pos_y;
	int	pos_x;

	y = -1;
	pos_y = par->player->pos_y - 192;
	pos_x = par->player->pos_x - 192;
	while (++y < 256)
	{
		x = -1;
		while (++x < 256)
		{
			if ((pos_y + y + 128) >= par->height * 64 || (pos_x + x
					+ 128) >= par->width * 64 || (pos_y + y) < 0 || (pos_x
					+ x) < 0)
				my_mlx_pixel_put(img, x, y, 0x000000);
			else if (par->map[(y + pos_y + 64) / 64][(x + pos_x + 64)
				/ 64] == '1')
				my_mlx_pixel_put(img, x, y, 0x000000);
			else
				my_mlx_pixel_put(img, x, y, 0xfafafa);
		}
	}
	ft_player(128, 128, img);
}

int	close_win(t_par *par)
{
	int	i;

	i = 0;
	mlx_destroy_image(par->mlx->mlx_p, par->mlx->data.img);
	while (i < 4)
	{
		mlx_destroy_image(par->mlx->mlx_p, par->tex[i].img->img);
		i++;
	}
	mlx_destroy_window(par->mlx->mlx_p, par->mlx->win_p);
	free_tex(par->tex);
	free_map(par->map);
  free(par->mlx);
	free(par);
	exit(0);
	return (0);
}

int	key_up(int key, t_par *par)
{
	if (key == 1493 || key == 119 || key == ARROW_UP_L)
		par->player->walkdir = 0;
	if (key == 1491 || key == 115 || key == ARROW_DOWN_L)
		par->player->walkdir = 0;
	if (key == ARROW_LEFT_L)
		par->player->turndir = 0;
	if (key == ARROW_RIGHT_L)
		par->player->turndir = 0;
	if (key == 97 || key == 1492)
		par->player->side_walk = 0;
	if (key == 100 || key == 1514)
		par->player->side_walk = 0;
	return (0);
}

int	key_down(int key, t_par *par)
{
	if (key == 65307)
	{
		close_win(par);
	}
	if (key == ARROW_LEFT_L)
		par->player->turndir = -1;
	if (key == ARROW_RIGHT_L)
		par->player->turndir = 1;
	if (key == 119 || key == ARROW_UP_L || key == 1493)
		par->player->walkdir = 1;
	if (key == 115 || key == ARROW_DOWN_L || key == 1491)
		par->player->walkdir = -1;
	if (key == 97 || key == 1492)
		par->player->side_walk = -1;
	if (key == 100 || key == 1514)
	{
		par->player->side_walk = 1;
	}
	return (0);
}

int	mlx(char **map, void *par1)
{
	t_par	*par;
	t_data	*data;

	par = par1;
	size_of_map(map, &par->width, &par->height);
	par->map = fill_map(map, par->width, par->height);
	par->mlx->mlx_p = mlx_init();
	par->mlx->win_p = mlx_new_window(par->mlx->mlx_p, WIDTH, HEIGHT, "CUB3D");
	data = &par->mlx->data;
	data->img = mlx_new_image(par->mlx->mlx_p, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->l_len,
			&data->endian);
	init_tex(par);
	render(par);
	mlx_hook(par->mlx->win_p, 2, 1L << 0, key_down, par);
	mlx_hook(par->mlx->win_p, 3, 1L << 1, key_up, par);
	mlx_hook(par->mlx->win_p, 17, 1L << 17, close_win, par);
	mlx_loop_hook(par->mlx->mlx_p, update, par);
	mlx_loop(par->mlx->mlx_p);
	return (0);
}
