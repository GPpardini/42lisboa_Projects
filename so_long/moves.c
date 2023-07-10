/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:44:51 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/10 21:15:44 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(void)
{
	int	y;

	y = get()->player.y;
	if (get()->player.y > 1 && get()->map[y - 1][get()->player.x] != '1')
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
	if ((get()->player.y < get()->map_y)
		&& get()->map[get()->player.y + 1][get()->player.x] != '1')
	{
		if (get()->game_e_flag == 1)
		{
			get()->map[get()->player.y][get()->player.x] = 'e';
			get()->game_e_flag = 0;
		}
		else
			get()->map[get()->player.y][get()->player.x] = '-';
		if (get()->map[get()->player.y + 1][get()->player.x] == 'e')
		{
			if (get()->game_c == 0)
				close_win();
			else
				get()->game_e_flag = 1;
		}
		if (get()->map[get()->player.y + 1][get()->player.x] == 'c')
			get()->game_c--;
		get()->map[get()->player.y + 1][get()->player.x] = 'P';
		get()->player.y++;
		map_print();
	}
}

void	move_left(void)
{
	int	x;

	x = get()->player.x;
	if ((get()->player.x > 1) && get()->map[get()->player.y][x - 1] != '1')
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
	if ((get()->player.x < get()->map_x)
		&& get()->map[get()->player.y][get()->player.x + 1] != '1')
	{
		if (get()->game_e_flag == 1)
		{
			get()->map[get()->player.y][get()->player.x] = 'e';
			get()->game_e_flag = 0;
		}
		else
			get()->map[get()->player.y][get()->player.x] = '-';
		if (get()->map[get()->player.y][get()->player.x + 1] == 'e')
		{
			if (get()->game_c == 0)
				close_win();
			else
				get()->game_e_flag = 1;
		}
		if (get()->map[get()->player.y][get()->player.x + 1] == 'c')
			get()->game_c--;
		get()->map[get()->player.y][get()->player.x + 1] = 'P';
		get()->player.x++;
		map_print();
	}
}
