/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:00:48 by afennoun          #+#    #+#             */
/*   Updated: 2024/03/01 21:13:16 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**fill_map(char **map, int width, int height)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	tmp = malloc(sizeof(char *) * (height + 1));
    if (!tmp)
        return (NULL);
	while (++i < height)
	{
		tmp[i] = malloc(sizeof(char) * (width + 1));
        if (!tmp[i])
            return (NULL);
		j = -1;
		while (++j < width)
		{
			if ((size_t)j < ft_strlen(map[i]))
				tmp[i][j] = map[i][j];
			else if ((size_t)j >= ft_strlen(map[i]))
				tmp[i][j] = '1';
		}
		tmp[i][j] = '\0';
	}
	tmp[i] = NULL;
	return (tmp);
}

void	size_of_map(char **map, int *x, int *y)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	*x = 0;
	a = 0;
	while (map[i])
		i++;
	while (a < i)
	{
		j = 0;
		while (map[a][j])
			j++;
		if (j > *x)
			*x = j;
		a++;
	}
	*y = i;
}

int	check_wall(float x, float y, char **map)
{
	float	grid_x;
	float	grid_y;
	int		height;
	int		width;

	grid_x = x / TILE_SIZE;
	grid_y = y / TILE_SIZE;
	size_of_map(map, &width, &height);
	if (grid_y >= (height) || grid_y < 0 || grid_x >= (width) || grid_x < 0)
		return (1);
	if (map[(int)grid_y][(int)grid_x] == '1')
		return (1);
	return (0);
}

unsigned int	get_pixel(t_data *img, int x, int y, t_tex *tex)
{
	char	*dst;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		return ;
	}
	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
