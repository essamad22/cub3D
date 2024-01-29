/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:51:49 by aakhtab           #+#    #+#             */
/*   Updated: 2024/01/28 04:57:11 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int i;
    int j;

    i = 0;
    j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 700, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 700, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    while (i < 192)
    {
        j = 0;
        while (j < 108)
        {
            my_mlx_pixel_put(&img, i, j, 0x00FFFFff);
            j++;
        }
        i++;
    }
    while (i < 700)
    {
        j = 0;
        while (j < 480)
        {
            my_mlx_pixel_put(&img, i, j, 0x0000ff);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}