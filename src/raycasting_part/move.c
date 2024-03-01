/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:29:58 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 19:04:30 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	update_player(t_par *par)
{
	int	c;

	c = 0;
	if (par->map[(int)par->player->pos_y / 64][(int)(par->player->pos_x
		+ par->player->dir_x) / 64] == '0')
	{
		par->player->pos_x += par->player->dir_x;
		c = 1;
	}
	if (par->map[(int)(par->player->pos_y + par->player->dir_y)
		/ 64][(int)par->player->pos_x / 64] == '0')
	{
		par->player->pos_y += par->player->dir_y;
		c = 1;
	}
	return (c);
}

int	update(t_par *par)
{
	int	c;

	c = 0;
	if (par->player->walkdir || par->player->turndir)
	{
		par->mov_step = par->player->walkdir * MOV_SPEED;
		par->player->rotangle += par->player->turndir * ROT_SPEED;
		par->player->dir_x = cos(par->player->rotangle) * par->mov_step;
		par->player->dir_y = sin(par->player->rotangle) * par->mov_step;
		c += update_player(par);
	}
	if (par->player->side_walk)
	{
		par->mov_step = par->player->rotangle + par->player->side_walk * (PI
				/ 2);
		par->player->dir_x = cos(par->mov_step) * MOV_SPEED;
		par->player->dir_y = sin(par->mov_step) * MOV_SPEED;
		c += update_player(par);
	}
	if (par->player->turndir || c)
	{
		par->player->rotangle = norm_angle(par->player->rotangle);
		render(par);
	}
	return (0);
}
