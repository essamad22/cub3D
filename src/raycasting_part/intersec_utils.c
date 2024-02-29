/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:15:34 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/29 20:57:46 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_h_angle(double angle)
{
	return (angle > 0 && angle < M_PI);
}

int	check_v_angle(double angle)
{
	return (angle < (M_PI / 2) || angle > (3 * M_PI) / 2);
}

double	norm_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	check_intersec(float p_a[2], float x_step, float y_step, t_par par)
{
	if (check_wall(p_a[0], p_a[1], par.map))
		return (1);
	p_a[0] += x_step;
	p_a[1] += y_step;
	return (0);
}

t_ray	set_ray(float x, float y, double angle, float distance)
{
	t_ray	ray;

	ray.x_hit = x;
	ray.y_hit = y;
	ray.distance = distance;
	ray.ray_angle = angle;
	return (ray);
}
