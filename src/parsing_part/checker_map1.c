/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:58:25 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 19:31:24 by aakhtab          ###   ########.fr       */
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
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (dir == 'E')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

void	ft_vectorize_ns(char dir, t_player *player)
{
	if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
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
		par->player->pos_x = *j * 64 + 32;
		par->player->pos_y = *i * 64 + 32;
		if (par->map[*i][*j] == 'N')
			par->player->rotangle = 3 * M_PI / 2;
		else if (par->map[*i][*j] == 'S')
			par->player->rotangle = M_PI / 2;
		else if (par->map[*i][*j] == 'W')
			par->player->rotangle = 0;
		else if (par->map[*i][*j] == 'E')
			par->player->rotangle = M_PI;
		ft_vectorize_dir(par->map[*i][*j], par->player);
		(*cc)++;
		par->map[*i][*j] = '0';
	}
}
