/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:29:58 by afennoun          #+#    #+#             */
/*   Updated: 2024/01/28 06:50:03 by afennoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forwad(t_par *par, t_player *player, int key)
{
    printf("player->posX: %f\n", player->posX);
    printf("player->posY: %f\n", player->posY);
    printf("player->dirX: %f\n", player->dirX);
    printf("player->dirY: %f\n", player->dirY);
	if (key == 119 || key == ARROW_UP_L || key == 1493)
	{
		if (par->map[(int)roundf((player->posY + player->dirY * mov_speed)
					/ 32)][(int)roundf(player->posX / 32)] == '0')
		{
			player->posY += player->dirY * mov_speed;
		}
		if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
					+ player->dirX * mov_speed) / 32)] == '0')
		{
			player->posX += player->dirX * mov_speed;
		}
		loop(par->map, par->mlx, par->win, par);
		printf("forward\n");
	}
}

void	move_backward(t_par *par, t_player *player, int key)
{
    printf("player->posX: %f\n", player->posX);
    printf("player->posY: %f\n", player->posY);
    printf("player->dirX: %f\n", player->dirX);
    printf("player->dirY: %f\n", player->dirY);
	if (key == 115 || key == ARROW_DOWN_L || key == 1491)
	{
		if (par->map[(int)roundf((player->posY - player->dirY * mov_speed)
					/ 32)][(int)roundf(player->posX / 32)] == '0')
		{
			player->posY -= player->dirY * mov_speed;
		}
		if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
					- player->dirX * mov_speed) / 32)] == '0')
		{
			player->posX -= player->dirX * mov_speed;
		}
		loop(par->map, par->mlx, par->win, par);
		printf("backward\n");
	}
}

void	move_left(t_par *par, t_player *player, int key)
{
    printf("player->posX: %f\n", player->posX);
    printf("player->posY: %f\n", player->posY);
    printf("player->dirX: %f\n", player->dirX);
    printf("player->dirY: %f\n", player->dirY);
	if (key == 97 || key == ARROW_LEFT_L || key == 1492)
	{
		if (par->map[(int)roundf((player->posY - player->dirX * mov_speed)
					/ 32)][(int)roundf(player->posX / 32)] == '0')
		{
			player->posY -= player->dirX * mov_speed;
		}
		if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
					+ player->dirY * mov_speed) / 32)] == '0')
		{
			player->posX += player->dirY * mov_speed;
		}
		loop(par->map, par->mlx, par->win, par);
		printf("left\n");
	}
}

void	move_right(t_par *par, t_player *player, int key)
{
    printf("player->posX: %f\n", player->posX);
    printf("player->posY: %f\n", player->posY);
    printf("player->dirX: %f\n", player->dirX);
    printf("player->dirY: %f\n", player->dirY);
	if (key == 100 || key == ARROW_RIGHT_L || key == 1514)
	{
		if (par->map[(int)roundf((player->posY + player->dirX * mov_speed)
					/ 32)][(int)roundf(player->posX / 32)] == '0')
		{
			player->posY += player->dirX * mov_speed;
		}
		if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
					- player->dirY * mov_speed) / 32)] == '0')
		{
			player->posX -= player->dirY * mov_speed;
		}
		loop(par->map, par->mlx, par->win, par);
		printf("right\n");
	}
}
