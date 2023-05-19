/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:16:44 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/18 18:28:45 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef unsigned int	t_ui;

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	t_ui	i;

	i = 0;
	if (!s)
		return (0);
	if ((start > ft_strlen(s) || \
		(len > ft_strlen(s) && start > ft_strlen(s))))
	{
		sub = malloc(1);
		if (!sub)
			return (0);
		sub[0] = 0;
		return (sub);
	}
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
