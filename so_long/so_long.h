/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:24 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/06 15:46:07 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "libft/libft.h"

typedef struct s_point
{
	int x;
	int y;
}	t_point;

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
	t_point	player;
}	t_data;

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

#endif
