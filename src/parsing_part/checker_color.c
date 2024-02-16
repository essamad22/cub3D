/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:58:22 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/05 11:38:33 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_comma(char *par)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (par[i])
	{
		if (par[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	remove_newline(char *par)
{
	int	i;

	i = 0;
	while (par[i])
	{
		if (par[i] == '\n')
			par[i] = '\0';
		i++;
	}
}

int	ft_strlen_space(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] == ' ')
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			return (10);
	}
	while (str[i] && str[i] != ' ')
	{
		j++;
		i++;
	}
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return (10);
	return (j);
}

int	split_color(char *col, t_par *par)
{
	int	i;
	int	j;

	i = 0;
	par->splited = ft_split_pars(col, ',', par);
	lst_add(par->col, lst_new(par->splited, par->col));
	while (par->splited[i])
	{
		j = 0;
		while (par->splited[i][j] == ' ')
			j++;
		if (!par->splited[i][j])
			return (1);
		while (par->splited[i][j])
		{
			if ((!ft_isdigit(par->splited[i][j]) && par->splited[i][j] != ' ')
				|| (ft_strlen_space(par->splited[i]) > 3))
			{
				// printf("%d", ft_strlen_space(par->splited[i]));
				return (1);
			}
			j++;
		}
		i++;
		if (i < 3 && !par->splited[i])
			return (1);
	}
	return (0);
}

int	check_color(char *par, t_par *parr)
{
	int	i;

	i = 0;
	if (!par)
		return (1);
	while (par[i] && par[i] == ' ')
		i++;
	if (par[i] == 'F' || par[i] == 'C')
		i++;
	if (par[i] == ' ')
	{
		while (par[i] && par[i] == ' ')
			i++;
	}
	else
		return (1);
	if (count_comma(&par[i]) != 2)
		return (1);
	if (split_color(&par[i], parr))
		return (1);
	return (0);
}
