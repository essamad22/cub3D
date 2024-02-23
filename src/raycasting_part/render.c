/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 03:55:32 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/22 05:44:07 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ray *set_rays(t_par *par, double fov, int num_rays)
{
    t_ray *rays;
    double ray_angle;
    int id;

    rays = malloc(sizeof(t_ray) * num_rays);
    ray_angle = par->player->rotAngle - (fov / 2);
    id = 0;
}
void render(t_par *par)
{
    t_ray  *rays;

    rays = set_rays(par, FOV, NUM_RAYS);
}
