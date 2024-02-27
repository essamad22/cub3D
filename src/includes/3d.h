/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:08:21 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/26 09:02:47 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _3D_H
#define _3D_H

#include "../../mlx_linux/mlx.h"
#include "parsing.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define rot_speed 1 * (PI / 180)
#define mov_speed 1.5
#define rot_angle PI / 2
#define RAY_ANGLE PI / 180

// typedef struct s_data
// {
//     void *img;
//     char *addr;
//     int   bits_per_pixel;
//     int   line_length;
//     int   endian;
// } t_data;
typedef struct s_ray_ut
{
    double tan_angle;
    double ray_down;
    double ray_right;
} t_ray_ut;

typedef struct s_ray
{
    char   id;
    double ray_angle;
    int    x_hit;
    int    y_hit;
    float  distance;
    char   dir;
    // double	camera_x;
    // double	dir_x;
    // double	dir_y;
    // int		map_x;
    // int		map_y;
    // int		step_x;
    // int		step_y;
    // double	sidedist_x;
    // double	sidedist_y;
    // double	delta_x;
    // double	delta_y;
    // double	wall_dist;
    // double	wall_x;
    // int		side;
    // int		line_height;
    // int		draw_start;
    // int		draw_end;
} t_ray;

int mlx(char **map, void *par);

void ft_vectorize_ew(char dir, t_player *player);
void ft_vectorize_ns(char dir, t_player *player);
void ft_vectorize_dir(char dir, t_player *player);

void ft_rotate_player(t_par *par, int key);
void ft_rotate_with_dir(t_par *par, float rot_dir);

// void loop(char **map, void *mlx, void *win, t_par *par);
void move_forwad(t_par *par, t_player *player, int key);
void move_backward(t_par *par, t_player *player, int key);
void move_left(t_par *par, t_player *player, int key);
void move_right(t_par *par, t_player *player, int key);

#endif
