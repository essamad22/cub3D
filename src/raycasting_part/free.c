/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:31:44 by aakhtab           #+#    #+#             */
/*   Updated: 2024/03/01 17:31:45 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tex(t_tex *tex)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(tex[i].path);
		free(tex[i].id);
		free(tex[i].img);
		i++;
	}
	free(tex);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
