/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:20:26 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/20 18:45:13 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	int				i;

	if (read(fd, 0, 0) < 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
		return (NULL);
	}
	if (!buffer[0])
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	line = seek_line(fd, buffer);
	over_read(buffer);
	return (line);
}