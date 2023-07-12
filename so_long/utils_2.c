/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:42:38 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/12 15:52:34 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_put_image(void *img_ptr, int j, int i)
{
	mlx_put_image_to_window(get()->mlx, 
	get()->mlx_win, img_ptr, j * 32, i * 32);
}

void	counter(void)
{	
	static int	i = 0;
	
	if (i > 0)
	{
		put_nbr(get()->moves);
		get()->moves++;
		write(1, "\n", 1);
	}
	else
	{
		get()->moves++;
		i++;
	}
}

void	player_pos(int y, int i)
{
	get()->map_p++;
	get()->player.y = y;
	get()->player.x = i;
}
