/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:46:31 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/10 20:47:37 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_create(void)
{
	img()->back.img = mlx_xpm_file_to_image(get()->mlx, "images/background.xpm", &img()->back.width, &img()->back.height);
	img()->wall.img = mlx_xpm_file_to_image(get()->mlx, "images/wall.xpm", &img()->back.width, &img()->back.height);
	img()->collectable.img = mlx_xpm_file_to_image(get()->mlx, "images/collectable.xpm", &img()->back.width, &img()->back.height);
	img()->player.img = mlx_xpm_file_to_image(get()->mlx, "images/player.xpm", &img()->back.width, &img()->back.height);
	img()->exit.img = mlx_xpm_file_to_image(get()->mlx, "images/exit.xpm", &img()->back.width, &img()->back.height);
}

int	str_len(char* str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	close_win(void)
{
	map_free();
	mlx_destroy_window(get()->mlx, get()->mlx_win);
	mlx_destroy_display(get()->mlx);
	mlx_loop_end(get()->mlx);
	free(get()->mlx);
	exit(0);
}