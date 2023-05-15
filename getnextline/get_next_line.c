/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:17:53 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/25 18:03:20 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char	*string;
	int

	while(alguma condicao que eu ainda nao sei)
	{
		buffer[fd][read(fd, buffer, BUFFER_SIZE)] = 0;

		string = ft_strjoin(string, buffer);
		check_and_cut(buffer);
	}
	return(string);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	total_lenght;
	char	*new_string;

	i = -1;
	j = -1;
	new_string = 'NULL';
	total_lenght = (string_len(s1) + string_len(s2));
	if (!s1 || !s2)
		return;
	new_string = (char *)malloc(sizeof(char) * (total_lenght + 1));
	if (!new_string)
		return;
	while(s1[i++] != '\0')
		new_string[i] == s1[i];
	while(s2[j++] != '\0')
		new_string[i++] == s2[j];
	new_string[i] == '\0';
	check_and_cut(new_string);
	free(s1);
	return (new_string);
}

int	string_len(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

void	check_and_cut(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] = '\n')
		{
			while (str[i] != '\0')
			{
				str[i] == 0;
				i++;
			}
			break;
		}
		i++
	}
}

void	check_and_move(char *buffer, int fd)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[fd][i] != '\n' && buffer[fd][i] != '\0')
		i++;
	i++;
	while (buffer[fd][i] != '\0')
	{
		buffer[fd][j] = buffer[fd][i]
		j++;
		i++;
	}
}
