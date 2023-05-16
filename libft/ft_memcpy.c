/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:10:09 by gpardini          #+#    #+#             */
/*   Updated: 2022/11/22 21:15:59 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t size)
{
	char	*cdest;
	char	*csrc;
	int		i;

	if (!str1 && !str2)
		return (NULL);
	cdest = (char *)str1;
	csrc = (char *)str2;
	i = -1;
	while ((int)size > ++i)
		cdest[i] = csrc[i];
	return (cdest);
}
