/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:09:44 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/10 21:18:14 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	param_check(char id, va_list args, int *countsize)
{
	if (id == 'c')
		printchar(va_arg(args, int), countsize);
	else if (id == 's')
		printstring(va_arg(args, char *), countsize);
	else if (id == 'p')
		printpointer(va_arg(args, unsigned long long), countsize);
	else if (id == 'd' || id == 'i')
		printnumber(va_arg(args, int), countsize);
	else if (id == 'u')
		printunsigned(va_arg(args, unsigned int), countsize);
	else if (id == 'x' || id == 'X')
		printhex(va_arg(args, unsigned int), id, countsize);
	else if (id == '%')
		printchar('%', countsize);
}

int	ft_printf(const char *fmt, ...)
{
	int		countsize;
	int		i;
	va_list	args;

	countsize = 0;
	i = 0;
	va_start(args, *fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			param_check(fmt[i + 1], args, &countsize);
			i++;
		}
		else
			printchar(fmt[i], &countsize);
		i++;
	}
	va_end(args);
	return (countsize);
}
