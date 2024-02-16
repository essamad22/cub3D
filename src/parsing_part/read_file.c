/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:49:54 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/05 11:54:23 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	open_file(char *file, t_par *par)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error\nFile not found", par);
	return (fd);
}
int	count_longest_line(char **file)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (file[i])
	{
		printf("%s\n", file[i]);
		sleep(10);
		j = 0;
		while (file[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}
int	get_file_size(char *file, t_par *par)
{
	int		fd;
	int		size;
	char	*line;
	// int		i;

	// i = 0;
	size = 0;
	fd = open_file(file, par);
	line = get_next_line(fd);
	while (line)
	{
		size++;
		lst_add(par->col, lst_new(line, par->col));
		line = get_next_line(fd);
	}
	par->map = malloc(sizeof(char *) * (size + 1));
	lst_add(par->col, lst_new(par->map, par->col));
	par->map[size] = NULL;
	return (size);
}

void	read_file(char *file, t_par *par, int size)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open_file(file, par);
	par->file = malloc(sizeof(char *) * (size + 1));
	lst_add(par->col, lst_new(par->file, par->col));
	par->file[size] = NULL;
	line = get_next_line(fd);
	lst_add(par->col, lst_new(line, par->col));
	while (line)
	{
		par->file[i] = (line);
		lst_add(par->col, lst_new(par->file[i], par->col));
		line = get_next_line(fd);
		lst_add(par->col, lst_new(line, par->col));
		i++;
	}
	par->file[i] = NULL;
	lst_add(par->col, lst_new(line, par->col));
	close(fd);
}
