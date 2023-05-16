/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:34:24 by gpardini          #+#    #+#             */
/*   Updated: 2023/01/08 12:17:34 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (count(n) + 1));
	if (!str)
		return (0);
	i = count(n);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[i] = '\0';
	while ((int)n > 0)
	{
		str[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}
