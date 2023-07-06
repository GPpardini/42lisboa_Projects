/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:16 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/06 15:57:49 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get(void)
{
	static t_data	data;
	return (&data);
}

void	map_size_y(int fd)
{
	int i;

	i = 0;
	while(get_next_line(fd) != 0)
		i++;
	get()->map_y = i;
}

int	str_len(char* str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	map_size_x(int fd)
{
	int i;
	int len;
	char *str;

	str = NULL;
	len = 1;
	i = 0;
	while(i < get()->map_y)
	{
		str = get_next_line(fd);
		if (i > 0 && (str_len(str) != len))
			write(1, "error\n", 6);
		len = str_len(str);
		i++;
	}
	get()->map_x = len - 1;
}

void	map_start(int fd)
{
	int i;
	i = get()->map_y;
	get()->map = (char **)malloc(sizeof(char *) * (i + 1));
	get()->map[i] = NULL;
	i = 0;
	while(i < get()->map_y)
	{
		get()->map[i] = (char *)malloc(sizeof(char) * get()->map_x + 1);
		if (!get()->map[i])
			write(1, "error\n", 6);
		get()->map[i] = get_next_line(fd);
		get()->map[i][get()->map_x] = 0;
		i++;
	}
}

void	map_print(void)
{
	int i = 0;
	while(i < get()->map_y)
	{
		printf("%s\n", get()->map[i]);
		i++;
	}
	printf("\n");
}

int	map_check_walls(char **map)
{
	int i;
	i = 0;
	while(i < get()->map_x)
	{
		if (map[0][i] != '1' || map[get()->map_y - 1][i] != '1')
			return(0);
		i++;
	}
	i = 0;
	while(i < get()->map_y)
	{
		if (map[i][get()->map_x - 1] != '1' || map[i][0] != '1')
			return(0);
		i++;
	}
	return(1);
}

int	map_check_pce(char **map)
{
	int i;
	int y;
	i = 0;
	y = 0;
	while(y < get()->map_y)
	{
		while(i < get()->map_x)
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
		return(0);
	else
		return(1);
}

void	flood(char **map, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] == 1 || map[cur.y][cur.x] == 'X')
		return;

	if (map[cur.y][cur.x] == 'C')
		get()->game_c++;
	if (map[cur.y][cur.x] == 'E')
		get()->game_e++;
	map[cur.y][cur.x] = 'X';
	flood(map, size, (t_point){cur.x - 1, cur.y});
	flood(map, size, (t_point){cur.x + 1, cur.y});
	flood(map, size, (t_point){cur.x, cur.y - 1});
	flood(map, size, (t_point){cur.x, cur.y + 1});
}

void	map_check_flood(char **map)
{
	flood(map, (t_point){get()->map_x, get()->map_y}, get()->player);

	if (!(get()->game_c == get()->map_c && get()->game_e == 1))
		printf("map does not have a possible trail\n");
}

void	map_check(void)
{
	if (!map_check_walls(get()->map))
		printf("map not surrounded by walls\n");
	if (!map_check_pce(get()->map))
		printf("map does not have a PCE proportion\n");
	map_check_flood(get()->map);

}

int main (int argc, char* argv[])
{
	(void)argc;
	map_size_y(open(argv[1], O_RDONLY));
	printf("map_y:%d\n\n", get()->map_y);
	map_size_x(open(argv[1], O_RDONLY));
	printf("map_x:%d\n\n", get()->map_x);
	map_start(open(argv[1], O_RDONLY));
	map_print();
	map_check();

	int i = 0;
	while(get()->map[i])
	{
		free(get()->map[i]);
		i++;
	}
	return(0);
}
