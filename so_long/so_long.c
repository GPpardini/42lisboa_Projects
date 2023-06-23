/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:16 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/23 20:47:26 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get(void)
{
	static t_data	data;
	return (&data);
}

void get_map(void)
{
	int fd;
	fd = get()->game.fd;
	get()->map.map[0] = (char *)malloc(sizeof(char) * 10);
	get()->map.map[0] = "123456789";
	get()->map.map[0][9] = '\0';
}

int main (int argc, char* argv[])
{
	(void)argc;
	
	get()->game.fd = open(argv[1], O_RDONLY);
	printf("debug\n");
	get_map();
	printf("%s\n", get()->map.map[0]);
	return(0);
}