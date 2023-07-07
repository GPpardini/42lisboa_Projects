/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:16 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/07 21:33:45 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get(void)
{
	static t_data	data;
	return (&data);
}

t_album	*img(void)
{
	static t_album	album;
	return (&album);
}

void	map_free(void)
{
	int i = 0;
	while(get()->map[i])
	{
		free(get()->map[i]);
		i++;
	}
	free(get()->map);
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

void	map_size_y(int fd)
{
	int i;
	char *temp;

	i = 0;
	temp = NULL;
	while(1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break;
		free(temp);
		i++;
	}
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
		free(str);
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
		get()->map[i] = get_next_line(fd);
		if (!get()->map[i])
			write(1, "error\n", 6);
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
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == 'X'
		|| map[cur.y][cur.x] == 'e' ||  map[cur.y][cur.x] == 'c' ||  map[cur.y][cur.x] == '-')
		return;

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
	//printf("game_c = (%d) || game_e = (%d)\n\n", get()->game_c, get()->game_e);
	//printf("map before = (%d)\n", map[cur.y][cur.x]);
	if (map[cur.y][cur.x] == '0')
		map[cur.y][cur.x] = '-';
	//printf("map after = (%d)\n", map[cur.y][cur.x]);
	flood(map, size, (t_point){cur.x - 1, cur.y});
	flood(map, size, (t_point){cur.x + 1, cur.y});
	flood(map, size, (t_point){cur.x, cur.y - 1});
	flood(map, size, (t_point){cur.x, cur.y + 1});
}

int	map_check_flood(char **map)
{
	flood(map, (t_point){get()->map_x, get()->map_y}, get()->player);

	if (!(get()->game_c == get()->map_c && get()->game_e == 1))
		return(0);
	else
		return(1);
}

void	map_check(void)
{
	if (!map_check_walls(get()->map))
		printf("map not surrounded by walls\n");
	if (!map_check_pce(get()->map))
		printf("map does not have a PCE proportion\n");
	if (!map_check_flood(get()->map))
		printf("map does not have a possible trail\n");
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



void	move_up(void)
{
	int y;
	y = get()->player.y;
	if(get()->player.y > 1 && get()->map[y - 1][get()->player.x] != '1')
	{
		if (get()->game_e_flag == 1)
		{
			get()->map[y][get()->player.x] = 'e';
			get()->game_e_flag = 0;
		}
		else
			get()->map[y][get()->player.x] = '-';
		if (get()->map[y - 1][get()->player.x] == 'e')
		{
			if (get()->game_c == 0)
				close_win();
			else
				get()->game_e_flag = 1;
		}
		if (get()->map[y - 1][get()->player.x] == 'c')
			get()->game_c--;
		get()->map[y - 1][get()->player.x] = 'P';
		get()->player.y--;
		map_print();
	}
}

void	move_down(void)
{
	int y;
	y = get()->player.y;
	if((get()->player.y < get()->map_y) && get()->map[y + 1][get()->player.x] != '1')
	{
		if (get()->game_e_flag == 1)
		{
			get()->map[y][get()->player.x] = 'e';
			get()->game_e_flag = 0;
		}
		else
			get()->map[y][get()->player.x] = '-';
		if (get()->map[y + 1][get()->player.x] == 'e')
		{
			if (get()->game_c == 0)
				close_win();
			else
				get()->game_e_flag = 1;
		}
		if (get()->map[y + 1][get()->player.x] == 'c')
			get()->game_c--;
		get()->map[y + 1][get()->player.x] = 'P';
		get()->player.y++;
		map_print();
	}
}

void	move_left(void)
{
	int x;
	x = get()->player.x;
	if((get()->player.x > 1) && get()->map[get()->player.y][x - 1] != '1')
	{
		if (get()->game_e_flag == 1)
		{
			get()->map[get()->player.y][x] = 'e';
			get()->game_e_flag = 0;
		}
		else
			get()->map[get()->player.y][x] = '-';
		if (get()->map[get()->player.y][x - 1] == 'e')
		{
			if (get()->game_c == 0)
				close_win();
			else
				get()->game_e_flag = 1;
		}
		if (get()->map[get()->player.y][x - 1] == 'c')
			get()->game_c--;
		get()->map[get()->player.y][x - 1] = 'P';
		get()->player.x--;
		map_print();
	}
}

void	move_right(void)
{
	int x;
	x = get()->player.x;
	if((get()->player.x < get()->map_x) && get()->map[get()->player.y][x + 1] != '1')
	{
		if (get()->game_e_flag == 1)
		{
			get()->map[get()->player.y][x] = 'e';
			get()->game_e_flag = 0;
		}
		else
			get()->map[get()->player.y][x] = '-';
		if (get()->map[get()->player.y][x + 1] == 'e')
		{
			if (get()->game_c == 0)
				close_win();
			else
				get()->game_e_flag = 1;
		}
		if (get()->map[get()->player.y][x + 1] == 'c')
			get()->game_c--;
		get()->map[get()->player.y][x + 1] = 'P';
		get()->player.x++;
		map_print();
	}
}

int	key_manager(int keycode)
{
	if (keycode == 0xff1b)
		close_win();
	if (keycode == 0xff52) //up
		move_up();
	if (keycode == 0xff54) //down
		move_down();
	if (keycode == 0xff53) //right
		move_right();
	if (keycode == 0xff51)
		move_left();
	return(0);
}

void	map_render(void)
{

}

void	image_create(void)
{
	img()->back.img = mlx_xpm_file_to_image(get()->mlx, "images/back", &img()->back.width, &img()->back.height);
	//img()->back.addr = mlx_get_data_addr(&img()->back.img,
	//&img()->back.bits_per_pixel, &img()->back.line_length, &img()->back.endian);
}

int main (int argc, char* argv[])
{
	(void)argc;
	map_size_y(open(argv[1], O_RDONLY));
	map_size_x(open(argv[1], O_RDONLY));
	map_start(open(argv[1], O_RDONLY));
	map_print();
	map_check();

	get()->mlx = mlx_init();
	get()->mlx_win = mlx_new_window(get()->mlx, 900, 700, "MyGame");
	image_create();
	mlx_key_hook(get()->mlx_win, key_manager, get());
	mlx_loop(get()->mlx);

	map_free();
	return(0);
}
