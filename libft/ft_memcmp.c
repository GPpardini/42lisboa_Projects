/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:49:35 by gpardini          #+#    #+#             */
/*   Updated: 2022/11/24 14:57:48 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;

int	ft_memcmp(const void *str1, const void *str2, size_t n)

{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((t_uc *)str1)[i] != ((t_uc *)str2)[i])
			return (((t_uc *)str1)[i] - ((t_uc *)str2)[i]);
		i++;
	}
	return (0);
}
