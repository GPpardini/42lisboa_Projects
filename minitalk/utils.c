/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:55:25 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/16 19:53:09 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	cnt;
	int	neg;
	int	num;

	cnt = 0;
	neg = 1;
	num = 0;
	if (!str)
		return (0);
	while ((str[cnt] >= '\t' && str[cnt] <= '\r') || str[cnt] == ' ')
		cnt++;
	if (str[cnt] == '-')
		neg = -1;
	if (str[cnt] == '+' || str[cnt] == '-')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		num = (str[cnt] - '0') + (num * 10);
		cnt++;
	}
	return (num * neg);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i + 1);
}

char	*ft_itoa(int num)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = num;
	str = NULL;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	if (!str)
		str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = (n % 10) + 48;
		n = (n / 10);
		i--;
	}
	return (str);
}
