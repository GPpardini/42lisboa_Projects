/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:23:17 by gpardini          #+#    #+#             */
/*   Updated: 2022/11/29 18:42:46 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int car)
{
	int	i;

	i = 0;
	if (car >= 0 && car <= 127)
		i = 1;
	return (i);
}
