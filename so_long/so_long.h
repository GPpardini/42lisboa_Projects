/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:24 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/23 20:45:15 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "libft/libft.h"


typedef struct s_game
{
	int 	fd;
	int		num;
}	t_game;

typedef struct s_map
{
	char **map;
	char *line;
}	t_map;

typedef struct s_img
{
	int images;
}	t_img;

typedef struct s_data
{
	t_game	game;
	t_map	map;
	t_img	img;
	
}	t_data;

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

#endif
