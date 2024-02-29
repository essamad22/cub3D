/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 03:55:32 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/29 17:09:45 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ray *get_ray(t_par *par, double fov, double num_rays)
{
    t_ray *rays;
    t_ray h_ray;
    t_ray v_ray;
    double ray_angle;
    int id;

    rays = malloc(sizeof(t_ray) * num_rays);
    ray_angle = par->player->rotAngle - (fov / 2);
    id = 0;
    while (id < NUM_RAYS)
    {
        h_ray = h_intersec(*par->player, norm_angle(ray_angle), *par);
        v_ray = v_intersec(*par->player, norm_angle(ray_angle), *par);
        rays[id] = get_best_ray(*par->player, h_ray, v_ray);
        ray_angle += (fov / NUM_RAYS);
        id++;
    }
    return (rays);
}

t_draw fill_wall(int x, int y, float wall_height, t_draw wall)
{
    wall.x = x;
    wall.y = y;
    wall.wall_height = wall_height;
    if (y < 0)
    {
        wall.wall_height = HEIGHT;
        wall.y = 0;
    }
    wall.width = 1;
    wall.height = wall_height;
    return (wall);
}

void render_3d(t_par *par, t_ray *rays, t_data *img, double angle)
{
    int i;
    float distance_to_vp;
    float wall_height;
    
    (void)img;
    distance_to_vp = ((WIDTH / 2.0) / tan(FOV / 2.0)) * TILE_SIZE;
    i = 0;
    while (i < NUM_RAYS)
    {
        wall_height = (distance_to_vp / rays[i].distance);
        // printf("rays[0].ray = %f\n", rays[0].ray_angle);
        // printf("angle = %f\n", angle);
        wall_height /= cos(angle - rays[i].ray_angle);
        par->mlx->wall = fill_wall(i, (HEIGHT - wall_height) / 2, wall_height, par->mlx->wall);
        draw_wall(par->mlx->wall, &par->mlx->data, rays[i], par);
        draw_ceiling(img, i, (HEIGHT / 2) - (wall_height / 2), par->color_C);
        draw_floor(img, i, (HEIGHT / 2) + (wall_height / 2), par->color_F);
        i++;
    }

}
void render(t_par *par)
{
    t_ray  *rays;

    rays = get_ray(par, FOV, (double)NUM_RAYS);
    render_3d(par, rays, &par->mlx->data, par->player->rotAngle);
    free(rays);
    loop(&par->mlx->data, par);
    mlx_put_image_to_window(par->mlx->mlx_p, par->mlx->win_p, par->mlx->data.img, 0, 0);
}
