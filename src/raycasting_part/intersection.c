/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:36:18 by aakhtab           #+#    #+#             */
/*   Updated: 2024/03/01 19:08:38 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// --------------------------------------
// point_a[0] = a_x || point_a[1] = a_y ||
// --------------------------------------
t_ray	h_intersec(t_player p, double angle, t_par par)
{
	t_ray_ut	r_u;
	float		x_step;
	float		y_step;
	float		p_a[2];

	r_u.ray_down = check_h_angle(angle);
	r_u.ray_right = check_v_angle(angle);
	r_u.tan_angle = tan(angle);
	p_a[1] = floor((double)p.pos_y / TILE_SIZE) * TILE_SIZE;
	if (r_u.ray_down)
		p_a[1] += TILE_SIZE;
	p_a[0] = p.pos_x + (p_a[1] - p.pos_y) / r_u.tan_angle;
	y_step = TILE_SIZE;
	if (!r_u.ray_down)
		y_step *= -1;
	x_step = TILE_SIZE / r_u.tan_angle;
	if ((!r_u.ray_right && x_step > 0) || (r_u.ray_right && x_step < 0))
		x_step *= -1;
	if (!r_u.ray_down)
		p_a[1] -= 1.0;
	while (p_a[0] >= 0 && p_a[0] <= par.width * TILE_SIZE && p_a[1] >= 0
		&& p_a[1] <= par.height * TILE_SIZE)
		if (check_intersec(p_a, x_step, y_step, par))
			break ;
	return (set_ray(p_a[0], p_a[1], angle, 0));
}

t_ray	v_intersec(t_player p, double angle, t_par par)
{
	t_ray_ut	r_u;
	float		x_step;
	float		y_step;
	float		point_a[2];

	r_u.ray_down = check_h_angle(angle);
	r_u.ray_right = check_v_angle(angle);
	r_u.tan_angle = tan(angle);
	point_a[0] = floor((p.pos_x / TILE_SIZE)) * TILE_SIZE;
	if (r_u.ray_right)
		point_a[0] += TILE_SIZE;
	point_a[1] = p.pos_y + (point_a[0] - p.pos_x) * r_u.tan_angle;
	x_step = TILE_SIZE;
	if (!r_u.ray_right)
		x_step *= -1;
	y_step = TILE_SIZE * r_u.tan_angle;
	if ((r_u.ray_down && y_step < 0) || (!r_u.ray_down && y_step > 0))
		y_step *= -1;
	if (!r_u.ray_right)
		point_a[0] -= 1.0;
	while (point_a[0] >= 0 && point_a[0] <= par.width * TILE_SIZE
		&& point_a[1] >= 0 && point_a[1] <= par.height * TILE_SIZE)
		if (check_intersec(point_a, x_step, y_step, par))
			break ;
	return (set_ray(point_a[0], point_a[1], angle, 0));
}

t_ray	get_best_ray(t_player p, t_ray h_r, t_ray v_r)
{
	float	v_dis;
	float	h_dis;

	v_dis = sqrtf(powf(v_r.x_hit - p.pos_x, 2) + powf(v_r.y_hit - p.pos_y, 2));
	h_dis = sqrtf(powf(h_r.x_hit - p.pos_x, 2) + powf(h_r.y_hit - p.pos_y, 2));
	if (v_dis < h_dis)
	{
		v_r.distance = v_dis;
		v_r.id = 'v';
		if (v_r.ray_angle <= PI / 2.0 || v_r.ray_angle >= 3.0 * PI / 2.0)
			v_r.dir = 'W';
		else
			v_r.dir = 'E';
		return (v_r);
	}
	h_r.id = 'h';
	h_r.distance = h_dis;
	if (h_r.ray_angle >= 0 && h_r.ray_angle <= PI)
		h_r.dir = 'S';
	else
		h_r.dir = 'N';
	return (h_r);
}
