/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:29:58 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 22:12:10 by afennoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	update_player(t_par *par)
{
	int	c;

	c = 0;
	if (par->map[(int)par->player->posY / 64][(int)(par->player->posX
			+ par->player->dirX) / 64] == '0')
	{
		par->player->posX += par->player->dirX;
		c = 1;
	}
	if (par->map[(int)(par->player->posY + par->player->dirY)
		/ 64][(int)par->player->posX / 64] == '0')
	{
		par->player->posY += par->player->dirY;
		c = 1;
	}
	return (c);
}

int	update(t_par *par)
{
	int	c;

	c = 0;
	if (par->player->walkDir || par->player->turnDir)
	{
		par->mov_step = par->player->walkDir * mov_speed;
		par->player->rotAngle += par->player->turnDir * rot_speed;
		par->player->dirX = cos(par->player->rotAngle) * par->mov_step;
		par->player->dirY = sin(par->player->rotAngle) * par->mov_step;
		c += update_player(par);
	}
	if (par->player->side_walk)
	{
		par->mov_step = 1 * mov_speed;
		// par->player->rotAngle += par->player->side_walk * rot_speed;
		par->player->dirX = cos(par->player->rotAngle + par->player->side_walk
				* (PI / 2)) * par->mov_step;
		par->player->dirY = sin(par->player->rotAngle + par->player->side_walk
				* (PI / 2)) * par->mov_step;
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
