/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:16 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/11 18:29:09 by gpardini         ###   ########.fr       */
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

int	key_manager(int keycode)
{
	if (keycode == 0xff1b)
		close_win();
	if (keycode == 0xff52)
		move_up();
	if (keycode == 0xff54)
		move_down();
	if (keycode == 0xff53)
		move_right();
	if (keycode == 0xff51)
		move_left();
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	map_size_y(open(argv[1], O_RDONLY));
	map_size_x(open(argv[1], O_RDONLY));
	map_start(open(argv[1], O_RDONLY));
	map_check();
	get()->mlx = mlx_init();
	get()->mlx_win = mlx_new_window(get()->mlx,
	get()->map_x * 32, get()->map_y * 32, "so_long");
	image_create();
	map_print();
	mlx_key_hook(get()->mlx_win, key_manager, get());
	mlx_hook(get()->mlx_win, 17, 1l << 17, (void *)close_win, get());
	mlx_loop(get()->mlx);
	map_free();
	return (0);
}
