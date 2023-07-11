/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:05:30 by gpardini          #+#    #+#             */
/*   Updated: 2023/07/11 17:37:13 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	found_breakline(char *string)
{
	int	i;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	return ((string[i] == '\n'));
}

char	*bl_strjoin(char *line, char *add)
{
	int		i;
	int		length[2];
	char	*joined;

	length[0] = 0;
	while (line && line[length[0]])
		length[0]++;
	length[1] = 0;
	while (add && add[length[1]] && add[length[1]] != '\n')
		length[1]++;
	joined = malloc(sizeof(char) * (length[0] + length[1] + \
		1 + (add[length[1]] == '\n')));
	if (!joined)
		return (NULL);
	i = -1;
	while (line && line[++i])
		joined[i] = line[i];
	i = -1;
	while (add && add[++i] && (i == 0 || add[i - 1] != '\n'))
		joined[length[0] + i] = add[i];
	joined[length[0] + i] = 0;
	if (line)
		free(line);
	return (joined);
}

char	*seek_line(int fd, char *buffer)
{
	char	*line;

	if (!buffer[0])
		return (NULL);
	line = NULL;
	while (buffer[0] && !found_breakline(buffer))
	{
		line = bl_strjoin(line, buffer);
		if (!line)
			return (NULL);
		buffer[read(fd, buffer, 10)] = 0;
	}
	return (bl_strjoin(line, buffer));
}

void	over_read(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i += (buffer[i] == '\n');
	j = 0;
	while (i < 10)
		buffer[j++] = buffer[i++];
	while (j < 10)
		buffer[j++] = 0;
}

char	*get_next_line(int fd)
{
	static char		buffer[FOPEN_MAX][10 + 1];
	char			*line;
	int				i;

	if (read(fd, 0, 0) < 0)
	{
		i = 0;
		while (i < 10)
			buffer[fd][i++] = 0;
		return (NULL);
	}
	if (!buffer[fd][0])
		buffer[fd][read(fd, buffer[fd], 10)] = 0;
	line = seek_line(fd, buffer[fd]);
	over_read(buffer[fd]);
	return (line);
}
