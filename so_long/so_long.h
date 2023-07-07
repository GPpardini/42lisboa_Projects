/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:24 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/07 21:28:59 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

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


#endif
