/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:46:31 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/11 18:31:13 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_create(void)
{
	img()->back.img = mlx_xpm_file_to_image(get()->mlx,
	"images/background.xpm", &img()->back.width, &img()->back.height);
	img()->wall.img = mlx_xpm_file_to_image(get()->mlx,
	"images/wall.xpm", &img()->back.width, &img()->back.height);
	img()->coll.img = mlx_xpm_file_to_image(get()->mlx,
	"images/coll.xpm", &img()->back.width, &img()->back.height);
	img()->player.img = mlx_xpm_file_to_image(get()->mlx,
	"images/player.xpm", &img()->back.width, &img()->back.height);
	img()->exit.img = mlx_xpm_file_to_image(get()->mlx,
	"images/exit.xpm", &img()->back.width, &img()->back.height);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

void	put_nbr(int n)
{
	char	num[] = "0123456789";

	if (n > 9)
	{
		put_nbr(n / 10);
		put_nbr(n % 10);
	}
	if (n < 10)
		write(1, &num[n % 10], 1);
}

void	close_win(void)
{
	map_free();
	mlx_destroy_image(get()->mlx, img()->back.img);
	mlx_destroy_image(get()->mlx, img()->wall.img);
	mlx_destroy_image(get()->mlx, img()->coll.img);
	mlx_destroy_image(get()->mlx, img()->player.img);
	mlx_destroy_image(get()->mlx, img()->exit.img);
	mlx_destroy_window(get()->mlx, get()->mlx_win);
	mlx_destroy_display(get()->mlx);
	mlx_loop_end(get()->mlx);
	free(get()->mlx);
	exit(0);
}

void	map_exit(int flag)
{
	if (flag == 0)
		write(1, "map is not square\n", 18);
	if (flag == 1)
		write(1, "map not surrounded by walls\n", 28);
	if (flag == 2)
		write(1, "map does not have a PCE proportion\n" , 35);
	if (flag == 3)
		write(1, "map does not have a possible trail\n", 35);
	map_free();
	exit(0);
}
