/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:41:48 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/12 15:51:39 by gpardini         ###   ########.fr       */
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
	int	i;

	j = 0;
	i = 0;
	counter();
	while (i < get()->map_y)
	{
		while (j < get()->map_x)
		{
			if (get()->map[i][j] == 'P')
				my_put_image(img()->player.img, j, i);
			else if (get()->map[i][j] == 'e')
				my_put_image(img()->exit.img, j, i);
			else if (get()->map[i][j] == 'c')
				my_put_image(img()->coll.img, j, i);
			else if (get()->map[i][j] == '-')
				my_put_image(img()->back.img, j, i);
			else if (get()->map[i][j] == '1')
				my_put_image(img()->wall.img, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}
