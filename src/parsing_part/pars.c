/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:45:28 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 19:15:02 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	remove_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void	tex_without_space(t_par *par)
{
	remove_space(par->tex_n);
	remove_space(par->tex_s);
	remove_space(par->tex_w);
	remove_space(par->tex_e);
}

int	final_check(t_par *par)
{
	if (loop_1(par))
		error("Error\nInvalid map0", par);
	if (check_valid(par))
		error("Error\nInvalid map1", par);
	if (loop_2(par))
		error("Error\nInvalid map2", par);
	if (check_color(par->color_f, par))
		error("Error\nInvalid color", par);
	else
		rgb(par, &par->col_f, par->f_clr);
	if (check_color(par->color_c, par))
		error("Error\nInvalid color", par);
	else
		rgb(par, &par->col_c, par->c_clr);
	tex_without_space(par);
	if (find_player(par))
		error("Error\n invalid player", par);
	return (0);
}
