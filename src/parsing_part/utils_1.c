/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:04:40 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 19:05:33 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strdup_pars(char *s1, t_par *par)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	lst_add(par->col, lst_new(buff, par->col));
	i = 0;
	if (!buff)
		return (NULL);
	while (*s1)
	{
		*(buff + i) = *s1++;
		i++;
	}
	*(buff + i) = '\0';
	return (buff);
}

void	error(char *str, t_par *par)
{
	printf("%s\n", str);
	if (!par || !par->col)
		exit(1);
	free_garbage(par->col);
	exit(1);
}

void	ft_init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->rotangle = 0;
	player->walkdir = 0;
	player->turndir = 0;
	player->side_walk = 0;
}

void	intialize_par(t_par *par)
{
	int	i;

	i = 0;
	par->tex_n = NULL;
	par->tex_s = NULL;
	par->tex_w = NULL;
	par->tex_e = NULL;
	par->color_f = NULL;
	par->color_c = NULL;
	par->map = NULL;
	par->mlx = malloc(sizeof(t_mlx));
	par->mov_step = 0;
	i = 0;
	ft_init_player(par->player);
	while (i < 6)
	{
		par->arr[i] = 0;
		i++;
	}
}

char	*ft_strchrr(char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (0);
}
