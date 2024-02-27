/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 03:55:32 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/26 10:52:59 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
        return ;
    }
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_wall(t_draw wall, t_data *img, t_ray ray, unsigned int color)
{
    int i;

    (void)ray;
    (void)img;
    i = wall.y;
    while (i <= wall.wall_height + wall.y)
    {
        my_mlx_pixel_put(img, wall.x, i, color);
        i++;
    }
}

void draw_ceiling(t_data *img, int x, int y, int color)
{
    int i;

    i = 0;
    while (i < y)
    {
        my_mlx_pixel_put(img, x, i, color);
        i++;
    }
}

void draw_floor(t_data *img, int x, int y, int color)
{
    int i;

    i = y;
    while (i < HEIGHT)
    {
        my_mlx_pixel_put(img, x, i, color);
        i++;
    }
}

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

t_draw fill_wall(int x, int y, float wall_height, t_draw draw)
{
    draw.x = x;
    draw.y = y;
    draw.wall_height = wall_height;
    if (y < 0)
    {
        draw.wall_height = HEIGHT;
        draw.y = 0;
    }
    draw.width = 1;
    draw.height = wall_height;
    return (draw);
}

void render_3d(t_par *par, t_ray *rays, t_data *img, double angle)
{
    int i;
    float distance_to_vp;
    float wall_height;
    
    (void)img;
    par->color_C = 0x0000AAFF;
    par->color_F = 0x00000000;
    unsigned int color;
    color = 0x460170;
    distance_to_vp = ((WIDTH / 2.0) / tan(FOV / 2.0)) * TILE_SIZE;
    i = 0;
    while (i < NUM_RAYS)
    {
        wall_height = (distance_to_vp / rays[i].distance);
        wall_height /= cos(angle - rays[i].ray_angle);
        par->mlx->wall = fill_wall(i, (HEIGHT - wall_height) / 2, wall_height, par->mlx->wall);
        draw_wall(par->mlx->wall, &par->mlx->data, rays[i], color);
        draw_ceiling(img, i, (HEIGHT / 2) - (wall_height / 2), 0xAAFFFF);
        draw_floor(img, i, (HEIGHT / 2) + (wall_height / 2), 0x707070);
        i++;
    }

}
void render(t_par *par)
{
    t_ray  *rays;

    rays = get_ray(par, FOV, (double)NUM_RAYS);
    render_3d(par, rays, &par->mlx->data, par->player->rotAngle);
    free(rays);
    mlx_put_image_to_window(par->mlx->mlx_p, par->mlx->win_p, par->mlx->data.img, 0, 0);
    loop(&par->mlx->data, par);
}
