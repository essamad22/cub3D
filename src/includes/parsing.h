/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:00:04 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/05 11:53:47 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// # include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "../3d/minilibx-linux/mlx.h"
// # include "../3d/3d.h"

typedef struct s_col
{
	struct s_col	*next;
	void			*ptr;
}					t_col;

typedef	struct	s_player
{
	float	posX;
	float	posY;
	double	dirX;
	double	dirY;
	float	planX;
	float	planY;
	float	tmp_driX;
	float	tmp_driY;
}	t_player;

typedef struct s_par
{
	t_col			**col;
	char			**map;
	char			**file;
	char			*tex_n;
	char			*tex_s;
	char			*tex_w;
	char			*tex_e;
	char			*color_f;
	char			*color_c;
	char			**splited;
	t_player		*player;
	int				arr[6];
	unsigned int	color_F;
	unsigned int	color_C;
	int				C_CLR[3];
	int				F_CLR[3];
	void 			*mlx;
	void 			*win;
}					t_par;

int                 final_check(t_par *par);
void				free_garbage(t_col **col);
void				error(char *str , t_par *par);
char				*ft_strdup_pars(char *str, t_par *par);
void				lst_add(t_col **alst, t_col *news);
t_col				*lst_new(void *ptr, t_col **col);
int					open_file(char *file , t_par *par);
int					count_longest_line(char **file);
int					get_texture_1(char *line, t_par *par);
int					get_texture_2(char *line, t_par *par);
int					get_file_size(char *file, t_par *par);
void				get_file(char *file, t_par *par);
int					get_map(char **line, t_par *par, int *j, int i);
char				*ft_strchrr(char *s, int c);
int					search_for_address(t_col **col, void *ptr);
void				intialize_par(t_par *par);
int					loop_1(t_par *par);
int					loop_2(t_par *par);
void				read_file(char *file, t_par *par, int size);
// char				*ft_strnstr(char *hay, char *ne, size_t len);
int					check_map(t_par *par);
int					find_player(t_par *par);
int					check_closed(t_par *par);
int					check_valid(t_par *par);
char				*ft_substr_pars(char *s, unsigned int st, size_t l);
char				*get_index(char *line);
int					ft_strcmp(char *par, char *cmp);
// int					ft_isdigit(int c);
char				**ft_split_pars(char *s, char c, t_par *par);
int					check_color(char *par, t_par *parr);
void				remove_newline(char *str);
int					ft_strlen_space(char *str);
void				rgb(t_par *par, unsigned int *color , int *clr);
// int 				ft_atoi(const char *str);
int					is_empty(char *str);
// int 				ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
