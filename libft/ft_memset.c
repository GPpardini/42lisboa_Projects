/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:49:35 by gpardini          #+#    #+#             */
/*   Updated: 2022/11/22 22:52:08 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t size)
{
	size_t	i;

	if (!size)
		return (str);
	i = -1;
	while (size > ++i)
		((char *)str)[i] = (char)value;
	return (str);
}
