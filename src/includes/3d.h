/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:08:21 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/05 11:01:24 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _3D_H
# define _3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include  "../../mlx_linux/mlx.h"
# include "parsing.h"


#define	rot_speed 0.1
#define	mov_speed 4 

typedef struct	s_data {
	
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;


int	mlx(char **map, void *par);


void    ft_vectorize_ew(char dir, t_player *player);
void    ft_vectorize_ns(char dir, t_player *player);
void	ft_vectorize_dir(char dir, t_player *player);

void    ft_rotate_player(t_par *par, int key);
void    ft_rotate_with_dir(t_par *par, float rot_dir);

void	loop(char **map, void *mlx, void *win, t_par *par);
void   move_forwad(t_par *par, t_player *player , int key);
void   move_backward(t_par *par, t_player *player , int key);
void   move_left(t_par *par, t_player *player , int key);
void   move_right(t_par *par, t_player *player , int key);

#endif
