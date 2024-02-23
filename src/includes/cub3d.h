/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:16:56 by aakhtab           #+#    #+#             */
/*   Updated: 2024/02/23 05:31:13 by aakhtab          ###   ########.fr       */
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
# define FOV 60 
# define PI 3.141593
# define WIDTH 320
# define HEIGHT 200
# define NUM_RAYS WIDTH



// ---utils-func---
void  size_of_map(char **map, int *x, int *y);
void stroke(void *mlx, void *win, t_par *par);
void  draw_square(void *mlx, void *win, int x, int y, unsigned int color);
void render(t_par *par);
int update(t_par *par);
int update_player(t_par *par, t_player *player);
#endif
