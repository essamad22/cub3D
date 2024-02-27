/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:29:58 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/23 14:14:55 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int update_player(t_par *par)
{
    int c = 0;
    if (par->map[(int)par->player->posY 
            / 32][(int)(par->player->posX + par->player->dirX) / 32] == '0')
    {
        par->player->posX += par->player->dirX;
        c = 1;
    }
    if (par->map[(int)(par->player->posY + par->player->dirY) 
            / 32][(int)par->player->posX / 32] == '0')
    {
        par->player->posY += par->player->dirY;
        c = 1;
    }
    return (c);
}

// void	move_forwad(t_par *par, t_player *player, int key)
// {
//     float walkdir = 1;
//     // calculate move step
//     par->mov_step = walkdir * mov_speed;
//     // calculate new player direction
//     player->dirX = cos(par->player->rotAngle) * par->mov_step;
//     player->dirY = sin(par->player->rotAngle) * par->mov_step;
// 	if (key == 119 || key == ARROW_UP_L || key == 1493 || key == 1514)
// 	{
//         if (par->map[(int)roundf((player->posY + player->dirY) / 32)][(int)roundf(player->posX
//                     / 32)] == '0')
//             player->posY += player->dirY;
//         if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
//                     + player->dirX) / 32)] == '0')
//             player->posX += player->dirX;
// 	// 				/ 32)][(int)roundf(player->posX / 32)] == '0')
// 	// 	{
// 	// 		player->posY += player->dirY * mov_speed;
// 	// 	}
// 	// 	if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
// 	// 				+ player->dirX * mov_speed) / 32)] == '0')
// 	// 	{
// 	// 		player->posX += player->dirX * mov_speed;
// 	// 	}
// 		loop(par->map, par->mlx, par->win, par);
// 	// 	printf("forward\n");
// 	}
// }
//
// void	move_backward(t_par *par, t_player *player, int key)
// {
//     float walkdir = -1;
//     par->mov_step = walkdir * mov_speed;
//     player->dirX = cos(par->player->rotAngle) * par->mov_step;
//     player->dirY = sin(par->player->rotAngle) * par->mov_step;
// 	if (key == 115 || key == ARROW_DOWN_L || key == 1491 || key == 1492)
// 	{
//         if (par->map[(int)roundf((player->posY + player->dirY) / 32)][(int)roundf(player->posX
//                     / 32)] == '0')
//             player->posY += player->dirY;
//         if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
//                     + player->dirX) / 32)] == '0')
//             player->posX += player->dirX;
// 	// 	if (par->map[(int)roundf((player->posY - player->dirY * mov_speed)
// 	// 				/ 32)][(int)roundf(player->posX / 32)] == '0')
// 	// 	{
// 	// 		player->posY -= player->dirY * mov_speed;
// 	// 	}
// 	// 	if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
// 	// 				- player->dirX * mov_speed) / 32)] == '0')
// 	// 	{
// 	// 		player->posX -= player->dirX * mov_speed;
// 	// 	}
// 		loop(par->map, par->mlx, par->win, par);
// 	// 	printf("backward\n");
// 	}
// }
//
// // void	move_left(t_par *par, t_player *player, int key)
// // {
// //     (void)par;
// //     (void)player;
// //     (void)key;
// // 	if (key == 97 || key == ARROW_LEFT_L || key == 1492)
// // 	{
// // 	// 	if (par->map[(int)roundf((player->posY - player->dirX * mov_speed)
// // 	// 				/ 32)][(int)roundf(player->posX / 32)] == '0')
// // 	// 	{
// // 	// 		player->posY -= player->dirX * mov_speed;
// // 	// 	}
// // 	// 	if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
// // 	// 				+ player->dirY * mov_speed) / 32)] == '0')
// // 	// 	{
// // 	// 		player->posX += player->dirY * mov_speed;
// // 	// 	}
// // 		loop(par->map, par->mlx, par->win, par);
// // 	// 	printf("left\n");
// // 	}
// // }
//
// // void	move_right(t_par *par, t_player *player, int key)
// // {
// //     (void)par;
// //     (void)player;
// //     (void)key;
// // 	if (key == 100 || key == ARROW_RIGHT_L || key == 1514)
// // 	{
// // 	// 	if (par->map[(int)roundf((player->posY + player->dirX * mov_speed)
// // 	// 				/ 32)][(int)roundf(player->posX / 32)] == '0')
// // 	// 	{
// // 	// 		player->posY += player->dirX * mov_speed;
// // 	// 	}
// // 	// 	if (par->map[(int)roundf(player->posY / 32)][(int)roundf((player->posX
// // 	// 				- player->dirY * mov_speed) / 32)] == '0')
// // 	// 	{
// // 	// 		player->posX -= player->dirY * mov_speed;
// // 	// 	}
// // 		loop(par->map, par->mlx, par->win, par);
// // 		printf("right\n");
// // 	}
// // }
//
