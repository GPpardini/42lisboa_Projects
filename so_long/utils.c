/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:46:31 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/11 14:00:22 by gpardini         ###   ########.fr       */
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

void	image_destroy(void)
{
	mlx_destroy_image(get()->mlx, img()->back.img);
	mlx_destroy_image(get()->mlx, img()->wall.img);
	mlx_destroy_image(get()->mlx, img()->collectable.img);
	mlx_destroy_image(get()->mlx, img()->player.img);
	mlx_destroy_image(get()->mlx, img()->exit.img);
}

int	str_len(char* str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	return(i);
}

void	close_win(void)
{
	map_free();
	image_destroy();
	mlx_destroy_window(get()->mlx, get()->mlx_win);
	mlx_destroy_display(get()->mlx);
	mlx_loop_end(get()->mlx);
	free(get()->mlx);
	exit(0);
}

void	map_exit(int flag)
{
	if (flag == 0)
		printf("map is not square\n");
	if (flag == 1)
		printf("map not surrounded by walls\n");
	if (flag == 2)
		printf("map does not have a PCE proportion\n");
	if (flag == 3)
		printf("map does not have a possible trail\n");
	map_free();
	exit(0);
}
