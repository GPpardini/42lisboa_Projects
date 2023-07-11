/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:43:48 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/11 17:51:22 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_walls(char **map)
{
	int	i;

	i = 0;
	while (i < get()->map_x)
	{
		if (map[0][i] != '1' || map[get()->map_y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < get()->map_y)
	{
		if (map[i][get()->map_x - 1] != '1' || map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_check_pce(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y < get()->map_y)
	{
		while (i < get()->map_x)
		{
			if (map[y][i] == 'P')
			{
				get()->map_p++;
				get()->player.x = i;
				get()->player.y = y;
			}
			if (map[y][i] == 'C')
				get()->map_c++;
			if (map[y][i] == 'E')
				get()->map_e++;
			i++;
		}
		y++;
		i = 0;
	}
	if ((get()->map_p != 1) || (get()-> map_e != 1) || get()->map_c == 0)
		return (0);
	else
		return (1);
}

void	map_flood(char **map, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == 'X'
		|| map[cur.y][cur.x] == 'e' || map[cur.y][cur.x] == 'c' || map[cur.y][cur.x] == '-')
		return ;
	if (map[cur.y][cur.x] == 'C')
	{
		map[cur.y][cur.x] = 'c';
		get()->game_c++;
	}
	if (map[cur.y][cur.x] == 'E')
	{
		map[cur.y][cur.x] = 'e';
		get()->game_e++;
	}
	if (map[cur.y][cur.x] == '0')
		map[cur.y][cur.x] = '-';
	map_flood(map, size, (t_point){cur.x - 1, cur.y});
	map_flood(map, size, (t_point){cur.x + 1, cur.y});
	map_flood(map, size, (t_point){cur.x, cur.y - 1});
	map_flood(map, size, (t_point){cur.x, cur.y + 1});
}

int	map_check_square(char **map)
{
	int	len;
	int	i;
	int	ln;

	i = 0;
	len = str_len(map[i]);
	ln = 0;
	while (map[i])
	{
		ln = str_len(map[i]);
		if (ln != len)
			return (0);
		i++;
	}
	return (1);
}

void	map_check(void)
{
	if (!map_check_square(get()->map))
		map_exit(0);
	if (!map_check_walls(get()->map))
		map_exit(1);
	if (!map_check_pce(get()->map))
		map_exit(2);
	map_flood(get()->map, (t_point){get()->map_x, get()->map_y}, get()->player);
	if (!(get()->game_c == get()->map_c && get()->game_e == 1))
		map_exit(3);
}
