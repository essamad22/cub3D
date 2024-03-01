/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:23:24 by aakhtab           #+#    #+#             */
/*   Updated: 2024/03/01 21:14:47 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_tex	*get_tex(char direction, t_par *par)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (par->tex[i].id[0] == direction)
			return (&par->tex[i]);
		i++;
	}
	return (NULL);
}

void	set_path(t_par *par)
{
	par->tex[0].path = par->tex_e;
	par->tex[0].id = ft_strdup("E");
	par->tex[1].path = par->tex_w;
	par->tex[1].id = ft_strdup("W");
	par->tex[2].path = par->tex_s;
	par->tex[2].id = ft_strdup("S");
	par->tex[3].path = par->tex_n;
	par->tex[3].id = ft_strdup("N");
}

void	init_tex(t_par *par)
{
	int	i;

	i = 0;
	par->tex = malloc(sizeof(t_tex) * 4);
    if (!par->tex)
        error("Error\n", par);
	set_path(par);
	while (i < 4)
	{
		par->tex[i].width = 0;
		par->tex[i].height = 0;
		par->tex[i].img = malloc(sizeof(t_data));
        if (!par->tex[i].img)
            error("Error\n", par);
		par->tex[i].img->img = mlx_xpm_file_to_image(par->mlx->mlx_p,
				par->tex[i].path, &par->tex[i].width, &par->tex[i].height);
		if (!par->tex[i].img->img)
			error("Error\n", par);
		par->tex[i].img->addr = mlx_get_data_addr(par->tex[i].img->img,
				&par->tex[i].img->bpp, &par->tex[i].img->l_len,
				&par->tex[i].img->endian);
		if (!par->tex[i].img->addr)
			error("Error\n", par);
		i++;
	}
}
