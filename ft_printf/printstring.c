/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:46:50 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/06 10:26:01 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printstring(char *string, int *countsize)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		write(1, &(string[i]), 1);
		i++;
	}
	(*countsize) += i;
}
