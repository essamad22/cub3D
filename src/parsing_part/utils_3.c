/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:09:43 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/22 03:48:10 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/parsing.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
unsigned int	to_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
void	rgb(t_par *par, unsigned int *color, int *clr)
{
	int	i;
	int	j;
	// int	k[3];
	// int	x;

	i = 0;
	j = 0;
	// x = 0;
	while (par->splited[i])
	{
		clr[j] = ft_atoi(par->splited[i]);
		if (clr[j] > 255 || clr[j] < 0)
			error("Error\ncolor out of range", par);
		i++;
		j++;
	}
	*color = to_rgb(clr[0], clr[1], clr[2]);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' && str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
