/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:16:56 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/26 09:27:26 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../lib/libft.h"
# include "../../mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
// -----------------PARSING-----------------
# include "parsing.h"
# include "3d.h"
//------------------------------------------
// -----LINUX-----
# define ESC_L 65307
# define ARROW_UP_L 65362
# define ARROW_DOWN_L 65364
# define ARROW_LEFT_L 65361
# define ARROW_RIGHT_L 65363
# define C_KEY_L 99
# define SPACE_KEY_L 32
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

// -----------------MACROS-----------------
# define TILE_SIZE 32
# define FOV 1.0472 
# define PI 3.141593
# define WIDTH 1100
# define HEIGHT 1000
# define wallsatrip 2
# define NUM_RAYS WIDTH



// ---utils-func---
void  size_of_map(char **map, int *x, int *y);
void  loop(t_data *img, t_par *par);
void stroke(t_data *img, t_par *par);
void  draw_square(t_data *img, int x, int y, unsigned int color);
void render(t_par *par);
int update(t_par *par);
int update_player(t_par *par);
t_ray *get_ray(t_par *par, double fov, double num_rays);
t_ray h_intersec(t_player player, double angle, t_par par);
t_ray v_intersec(t_player player, double angle, t_par par);
t_ray get_best_ray(t_player player, t_ray h_ray, t_ray v_ray);
int check_h_angle(double angle);
int check_v_angle(double angle);
double norm_angle(double angle);
int is_wall(char c);
int check_wall(float x, float y, char **map);
int check_intersec(float p_a[2], float x_step, float y_step, t_par par);
t_ray set_ray(float x, float y, double angle, float distance);
#endif
