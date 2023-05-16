/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:45:04 by gpardini          #+#    #+#             */
/*   Updated: 2022/11/29 18:53:37 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldest;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	ldest = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && ldest + 1 < size)
	{
		dst[ldest] = src[i];
		ldest++;
		i++;
	}
	dst[ldest] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
