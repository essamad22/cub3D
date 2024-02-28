/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:29:58 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/28 20:47:22 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int update_player(t_par *par)
{
    int c = 0;
    if (par->map[(int)par->player->posY 
            / 64][(int)(par->player->posX + par->player->dirX) / 64] == '0')
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

