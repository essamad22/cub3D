/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:58:25 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 14:32:27 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map(t_par *par)
{
	int	i;
	int	j;

	i = 0;
	while (par->map[i])
	{
		j = 0;
		while (par->map[i][j])
		{
			if (par->map[i][j] != '1' && par->map[i][j] != '0'
				&& par->map[i][j] != ' ' && par->map[i][j] != '\n'
				&& par->map[i][j] != 'N' && par->map[i][j] != 'S'
				&& par->map[i][j] != 'E' && par->map[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_vectorize_ew(char dir, t_player *player)
{
	if (dir == 'W')
	{
		player->dirX = 1;
		player->dirY = 0;
	}
	else if (dir == 'E')
	{
		player->dirX = -1;
		player->dirY = 0;
	}
}

void	ft_vectorize_ns(char dir, t_player *player)
{
	if (dir == 'S')
	{
		player->dirX = 0;
		player->dirY = 1;
	}
	else if (dir == 'N')
	{
		player->dirX = 0;
		player->dirY = -1;
	}
}

void	ft_vectorize_dir(char dir, t_player *player)
{
	ft_vectorize_ew(dir, player);
	ft_vectorize_ns(dir, player);
}

void	condition(t_par *par, int *i, int *j, int *cc)
{
	if (par->map[*i][*j] == 'N' || par->map[*i][*j] == 'S'
		|| par->map[*i][*j] == 'E' || par->map[*i][*j] == 'W')
	{
		par->player->posX = *j * 64 + 32;
		par->player->posY = *i * 64 + 32;
        if (par->map[*i][*j] == 'N')
            par->player->rotAngle = 3 * M_PI / 2;
        else if (par->map[*i][*j] == 'S')
            par->player->rotAngle = M_PI / 2;
        else if (par->map[*i][*j] == 'E')
            par->player->rotAngle = 0;
        else if (par->map[*i][*j] == 'W')
            par->player->rotAngle = M_PI;
		ft_vectorize_dir(par->map[*i][*j], par->player);
		(*cc)++;
		par->map[*i][*j] = '0';
	}
}
