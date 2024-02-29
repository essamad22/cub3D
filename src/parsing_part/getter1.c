/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:51:34 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 22:24:44 by afennoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture_1(char *line, t_par *par)
{
	while (line && *line == ' ')
		line++;
	if (ft_strnstr(line, "NO ", 3))
	{
		par->arr[0]++;
		par->tex_n = ft_strdup_pars(get_index(line), par);
		remove_newline(par->tex_n);
	}
	else if (ft_strnstr(line, "SO ", 3))
	{
		par->arr[1]++;
		par->tex_s = ft_strdup_pars(get_index(line), par);
		remove_newline(par->tex_s);
	}
	if (get_texture_2(line, par) == 0)
		return (0);
	return (1);
}

int	get_texture_2(char *line, t_par *par)
{
	if (ft_strnstr(line, "WE ", 3))
	{
		par->arr[2]++;
		par->tex_w = ft_strdup_pars(get_index(line), par);
		remove_newline(par->tex_w);
	}
	else if (ft_strnstr(line, "EA ", 3))
	{
		par->arr[3]++;
		par->tex_e = ft_strdup_pars(get_index(line), par);
		remove_newline(par->tex_e);
	}
	else
		return (0);
	return (1);
}

int	get_color(char *line, t_par *par)
{
	while (line && *line == ' ')
		line++;
	if (ft_strnstr(line, "F ", ft_strlen(line)))
	{
		par->arr[4]++;
		par->color_f = ft_strdup_pars(line, par);
		remove_newline(par->color_f);
	}
	else if (ft_strnstr(line, "C ", ft_strlen(line)))
	{
		par->arr[5]++;
		par->color_c = ft_strdup_pars(line, par);
		remove_newline(par->color_c);
	}
	else
		return (0);
	return (1);
}

int	is_texter(char *line)
{
	if (ft_strnstr(line, "NO ", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "SO ", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "WE ", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "EA ", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "F ", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "C ", ft_strlen(line)))
		return (1);
	else
		return (0);
}

int	get_map(char **line, t_par *par, int *j, int i)
{
	if (is_texter(line[i]))
	{
		par->map[*j] = ft_strdup_pars(" ", par);
		*j = *j + 1;
	}
	if (!is_texter(line[i]))
	{
		if (!line[i + 1])
		{
			par->map[*j] = ft_substr_pars(line[i], 0, ft_strlen(line[i]));
			lst_add(par->col, lst_new(par->map[*j], par->col));
		}
		else
		{
			par->map[*j] = ft_substr_pars(line[i], 0, ft_strlen(line[i]) - 1);
			lst_add(par->col, lst_new(par->map[*j], par->col));
		}
		*j = *j + 1;
	}
	else
		return (0);
	return (1);
}
