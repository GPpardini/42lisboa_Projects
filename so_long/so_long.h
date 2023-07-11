/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:24 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/11 11:13:35 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_album
{
	t_image	back;
	t_image	wall;
	t_image	player;
	t_image	exit;
	t_image	collectable;
} t_album;

typedef struct s_data
{
	char** map;
	char *line;
	int		map_y;
	int		map_x;
	int		map_p;
	int		map_c;
	int		map_e;
	int		game_c;
	int		game_e;
	int		game_e_flag;
	void	*mlx;
	void	*mlx_win;
	t_point	player;
}	t_data;

t_data	*get(void);
t_album	*img(void);
int		key_manager(int keycode);
void	map_start(int fd);
void	map_free(void);
void	map_exit(int flag);
void	map_print(void);
void	map_size_y(int fd);
void	map_size_x(int fd);
void	map_check(void);
int		map_check_walls(char **map);
int		map_check_pce(char **map);
int		map_check_flood(char **map);
void	map_flood(char **map, t_point size, t_point cur);
void	move_up(void);
void	move_down(void);
void	move_left(void);
void	move_right(void);
void	image_create(void);
int		str_len(char* str);
void	close_win(void);
char	*get_next_line(int fd);

#endif
