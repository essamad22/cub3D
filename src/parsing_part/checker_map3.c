/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:08:31 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 22:08:56 by afennoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
