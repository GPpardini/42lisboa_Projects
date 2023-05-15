/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:47:48 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/27 17:50:23 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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

//caso ache um /n a minha funcao pode parar, devolver um numero para eu saber onde cortar e eu corto do proprio buffer exatamente onde parou
//ja que eu so preciso devolver uma linha mesmo, ao invez de fazer uma funcao pra saber onde esta o ewline no buffer e mover tudo,
// tambem posso fazer uma funcao de mover as coisas em uma string pra facilitar a miha vida no buffer. e para caso tenha varias newlines
// no buffer eu posso primeiro ler o buffer para devolver a string? essa e uma duvida
// oque acontece caso tenha varias newlines no meu buffer, ele vai dar read denovo e vai se perder oque eu ja li, ou ele continua exatamente da onde eu parei??


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
