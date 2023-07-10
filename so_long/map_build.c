/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:41:48 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/10 23:34:23 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(void)
{
	int	i;

	i = 0;
	while (get()->map[i])
	{
		free(get()->map[i]);
		i++;
	}
	free(get()->map);
}

void	map_size_y(int fd)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		free (temp);
		i++;
	}
	get()->map_y = i;
}

void	map_size_x(int fd)
{
	int		i;
	int		len;
	char	*str;

	str = NULL;
	len = 1;
	i = 0;
	while (i < get()->map_y)
	{
		str = get_next_line(fd);
		if (i > 0 && (str_len(str) != len))
			write(1, "error\n", 6);
		len = str_len(str);
		free(str);
		i++;
	}
	get()->map_x = len - 1;
}

void	map_start(int fd)
{
	int	i;

	i = get()->map_y;
	get()->map = (char **)malloc(sizeof(char *) * (i + 1));
	get()->map[i] = NULL;
	i = 0;
	while (i < get()->map_y)
	{
		get()->map[i] = get_next_line(fd);
		if (!get()->map[i])
			write(1, "error\n", 6);
		get()->map[i][get()->map_x] = 0;
		i++;
	}
}

void	map_print(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < get()->map_y)
	{
		j = 0;
		while (j < get()->map_x)
		{
			if (get()->map[i][j] == 'P')
				mlx_put_image_to_window(get()->mlx,get()->mlx_win, img()->player.img, j * 32, i * 32);
			else if (get()->map[i][j] == 'e')
				mlx_put_image_to_window(get()->mlx, get()->mlx_win, img()->exit.img, j * 32, i * 32);
			else if (get()->map[i][j] == 'c')
				mlx_put_image_to_window(get()->mlx, get()->mlx_win, img()->collectable.img, j * 32, i * 32);
			else if (get()->map[i][j] == '-')
				mlx_put_image_to_window(get()->mlx, get()->mlx_win, img()->back.img, j * 32, i * 32);
			else if (get()->map[i][j] == '1')
				mlx_put_image_to_window(get()->mlx, get()->mlx_win, img()->wall.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
