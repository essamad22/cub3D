/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:58:25 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/28 20:50:53 by aakhtab          ###   ########.fr       */
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

int	find_player(t_par *par)
{
	int	i;
	int	j;
	int	cc;

	// t_player	*player;
	cc = 0;
	i = 0;
	// player = par->player;
	if (par->map[i] == NULL)
		error("Error\nInvalid map position", par);
	while (par->map[i])
	{
		j = 0;
		while (par->map[i][j])
		{
			if (par->map[i][j] == 'N' || par->map[i][j] == 'S'
				|| par->map[i][j] == 'E' || par->map[i][j] == 'W')
			{
				par->player->posX = j * 64 + 32;
				par->player->posY = i * 64 + 32;
				ft_vectorize_dir(par->map[i][j], par->player);
				cc++;
				par->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (cc != 1)
		return (1);
	return (0);
}

int	check_white(char **map, int i, int j)
{
	if (i == 0 || (!map[i - 1] || !map[i + 1]))
		return (1);
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' '
		|| map[i + 1][j] == ' ')
		return (1);
	if (map[i][j - 1] == '\0' || map[i][j + 1] == '\0' || map[i - 1][j] == '\0'
		|| map[i + 1][j] == '\0')
		return (1);
	return (0);
}
int	is_empty(char *map)
{
	int	i;

	i = 0;
	while (map[i] && (map[i] == ' ' || map[i] == '\n'))
		i++;
	if (map[i] == '\0')
		return (1);
	return (0);
}

void	remove_last_lines(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	i--;
	while (i > 0 && is_empty(map[i]))
	{
		j = 0;
		while (map[i])
		{
			map[i] = '\0';
			j++;
		}
		i--;
	}
}
void	remove_first_lines(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && is_empty(str[i]))
		i++;
	j = 0;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
}

int	check_closed(t_par *par)
{
	int	i;
	int	j;

	i = 0;
	remove_first_lines(par->map);
	remove_last_lines(par->map);
	while (par->map[i])
	{
		j = 0;
		if (is_empty(par->map[i]))
			return (1);
		while (par->map[i][j])
		{
			if (par->map[i][j] == '0' || par->map[i][j] == 'N'
				|| par->map[i][j] == 'S' || par->map[i][j] == 'E'
				|| par->map[i][j] == 'W')
			{
				if (check_white(par->map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid(t_par *par)
{
	if (check_map(par))
		return (1);
	if (check_closed(par))
		return (1);
	return (0);
}
