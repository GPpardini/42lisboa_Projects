/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:45:34 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/06 10:25:53 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printnumber(int num, int *countsize)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*countsize) += 11;
		return ;
	}
	if (num < 0)
	{
		printchar('-', countsize);
		printnumber(num * -1, countsize);
	}
	else
	{
		if (num > 9)
			printnumber(num / 10, countsize);
		printchar(num % 10 + '0', countsize);
	}
}
