/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 06:13:22 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 23:00:02 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_texture(char *par)
{
	if (!par)
		return (1);
	if (ft_strcmp(par, ".xpm"))
	{
		printf("%s\n", par);
		return (1);
	}
	return (0);
}

int	loop_2(t_par *par)
{
	if (check_texture(par->tex_n))
		return (1);
	if (check_texture(par->tex_s))
		return (1);
	if (check_texture(par->tex_w))
		return (1);
	if (check_texture(par->tex_e))
		return (1);
	else
		return (0);
}
