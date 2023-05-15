/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:40:04 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/06 11:06:22 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_hex(unsigned int num, char id, int *countsize)
{
	if (num >= 16)
	{
		p_hex(num / 16, id, countsize);
		p_hex(num % 16, id, countsize);
	}
	else
	{
		if (num <= 9)
			printchar((num + '0'), countsize);
		else
		{
			if (id == 'x')
				printchar((num - 10 + 'a'), countsize);
			if (id == 'X')
				printchar((num - 10 + 'A'), countsize);
		}
	}
}

void	printhex(unsigned int num, char id, int *countsize)
{
	if (num == 0)
		printchar(0, countsize);
	else
		p_hex(num, id, countsize);
}
