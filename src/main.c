/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:51:49 by aakhtab           #+#    #+#             */
/*   Updated: 2024/03/01 23:07:47 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/parsing.h"
#include <math.h>

int	main(int ac, char **av)
{
	int		size;
	t_par	*par;
	t_col	*col;

	par = NULL;
	if (ac != 2 || ft_strcmp(av[1], ".cub"))
		error("Error\nWrong number of arguments", par);
	par = malloc(sizeof(t_par));
	par->player = malloc(sizeof(t_player));
	col = malloc(sizeof(t_col));
	if (!par || !col || !par->player)
		error("Error\n", par);
	col->ptr = NULL;
	col->next = NULL;
	par->col = &col;
	lst_add(par->col, lst_new(par->player, par->col));
	intialize_par(par);
	size = get_file_size(av[1], par);
	read_file(av[1], par, size);
	if (final_check(par))
		error("Error\nInvalid map", par);
	mlx(par->map, par);
	free_tex(par->tex);
	free(par);
	return (0);
}
