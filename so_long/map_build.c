/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:41:48 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/11 18:18:33 by gpardini         ###   ########.fr       */
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
		if (temp == NULL || *temp == '\n')
			break ;
		free (temp);
		i++;
	}
	if (temp)
		free (temp);
	get()->map_y = i;
}

void	map_size_x(int fd)
{
	char	*str;
	int		len;
	int		i;

	str = NULL;
	len = 0;
	i = 0;
	while (i < get()->map_y)
	{
		str = get_next_line(fd);
		len = str_len(str);
		free (str);
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
		get()->map[i][str_len(get()->map[i])] = 0;
		i++;
	}
}

void	map_print(void)
{
	int	j;

	j = 0;
	get()->i = 0;
	while (get()->i++ < get()->map_y)
	{
		while (j++ < get()->map_x)
		{
			if (get()->map[get()->i][j] == 'P')
				mlx_put_image_to_window(get()->mlx,
					get()->mlx_win, img()->player.img, j * 32, get()->i * 32);
			else if (get()->map[get()->i][j] == 'e')
				mlx_put_image_to_window(get()->mlx,
					get()->mlx_win, img()->exit.img, j * 32, get()->i * 32);
			else if (get()->map[get()->i][j] == 'c')
				mlx_put_image_to_window(get()->mlx,
					get()->mlx_win, img()->coll.img, j * 32, get()->i * 32);
			else if (get()->map[get()->i][j] == '-')
				mlx_put_image_to_window(get()->mlx,
					get()->mlx_win, img()->back.img, j * 32, get()->i * 32);
			else if (get()->map[get()->i][j] == '1')
				mlx_put_image_to_window(get()->mlx,
					get()->mlx_win, img()->wall.img, j * 32, get()->i * 32);
		}
	}
}

// void	counter(void)
// {
// 	put_nbr(get()->moves);
// 	get()->moves++;
// 	write(1, "\n", 1);
// }

/* ************************************************************************** */