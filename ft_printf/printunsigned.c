/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:40 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/06 10:26:09 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printunsigned(unsigned int num, int *countsize)
{
	if (num >= 10)
		printunsigned(num / 10, countsize);
	printchar(num % 10 + '0', countsize);
}
