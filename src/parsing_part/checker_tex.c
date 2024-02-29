/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 06:13:22 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 22:04:44 by afennoun         ###   ########.fr       */
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
		printf("Error\nTexture not found\n");
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
