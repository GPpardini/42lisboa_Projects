/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:56:00 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/06 11:07:44 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_pointer(unsigned long long num, int *countsize)
{
	if (num >= 16)
	{
		p_pointer(num / 16, countsize);
		p_pointer(num % 16, countsize);
	}
	else
	{
		if (num <= 9)
			printchar((num + '0'), countsize);
		else
			printchar((num - 10 + 'a'), countsize);
	}
}

void	printpointer(unsigned long long ptr, int *countsize)
{
	if (ptr == 0)
		printchar(0, countsize);
	else
		p_pointer(ptr, countsize);
}
