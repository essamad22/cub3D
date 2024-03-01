/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:06:22 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 19:07:45 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_player(t_par *par)
{
	int	i;
	int	j;
	int	cc;

	cc = 0;
	i = 0;
	if (par->map[i] == NULL)
		error("Error\nInvalid map position", par);
	while (par->map[i])
	{
		j = 0;
		while (par->map[i][j])
		{
			condition(par, &i, &j, &cc);
			j++;
		}
		i++;
	}
	if (cc != 1)
		return (1);
	return (0);
}

int	check_white(char **map, size_t i, size_t j)
{
	if (i == 0 || (!map[i - 1] || !map[i + 1]))
		return (1);
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' '
		|| ft_strlen(map[i - 1]) < j || ft_strlen(map[i + 1]) < j
		|| map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
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
			map[i] = NULL;
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
	str[j] = NULL;
}
