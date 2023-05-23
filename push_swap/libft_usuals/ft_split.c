/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:34:31 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/23 19:53:32 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	m_str(char const *s, char **split, char c)
{
	int	words;
	int	leng;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			words++;
		leng = 0;
		while (s[leng] != c && s[leng] != '\0')
			leng++;
		if (split && leng)
			split[words - 1] = ft_substr(s, 0, leng);
		s += leng;
	}
	if (split)
		split[words] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **) malloc(sizeof(char *) * (m_str(s, NULL, c) + 1));
	if (!split)
		return (0);
	m_str(s, split, c);
	return (split);
}
