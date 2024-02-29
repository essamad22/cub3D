/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_color2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:28:39 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 22:31:29 by afennoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
