/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:24:33 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 22:27:47 by afennoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_arr(int *arr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (arr[i] > 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_ordre(t_par *par)
{
	int	i;
	int	cc;

	i = 0;
	cc = 0;
	while (par->file[i] && (is_empty(par->file[i]) || is_texter(par->file[i])))
	{
		if (is_texter(par->file[i]))
			cc++;
		i++;
	}
	if (cc == 6)
		return (0);
	return (1);
}

int	loop_1(t_par *par)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_ordre(par))
		return (1);
	while (par->file[i])
	{
		get_map(par->file, par, &j, i);
		get_texture_1(par->file[i], par);
		get_color(par->file[i], par);
		i++;
	}
	par->map[j] = NULL;
	if (check_arr(par->arr))
		return (1);
	return (0);
}
