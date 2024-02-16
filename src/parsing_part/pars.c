/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:45:28 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/05 11:39:32 by aakhtab          ###   ########.fr       */
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
	int	size;

	if (loop_1(par))
		error("Error\nInvalid map0", par);
	if (check_valid(par))
		error("Error\nInvalid map1", par);
	if (loop_2(par))
		error("Error\nInvalid map2", par);
	if (check_color(par->color_f, par))
		error("Error\nInvalid color", par);
	else
		rgb(par, &par->color_F, par->F_CLR);
	if (check_color(par->color_c, par))
		error("Error\nInvalid color", par);
	else
		rgb(par, &par->color_C, par->C_CLR);
	tex_without_space(par);
	if (find_player(par))
		error("Error\n invalid player", par);
	printf("WE %s\n", par->tex_w);
	printf("NO %s\n", par->tex_n);
	printf("SO %s\n", par->tex_s);
	printf("EA %s\n", par->tex_e);
	printf("F %d\n", par->color_F);
	printf("C %d\n", par->color_C);
	size = 0;
	while (par->map[size])
	{
		printf("%s\n", par->map[size]);
		size++;
	}
	return (0);
}
