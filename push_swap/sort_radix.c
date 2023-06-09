/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:07:52 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/09 18:46:41 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	last_bit(int num)
{
	int	pos;
	int	bit;

	pos = 0;
	bit = 0;
	num--;
	while (bit < 32)
	{
		if ((num & (1 << bit)) && bit > pos)
			pos = bit;
		bit++;
	}
	return (pos);
}

void	sort_radix(void)
{
	int	round;
	int	size;
	int	bit;

	round = last_bit(list_size(get()->head_a));
	bit = 0;
	while (round >= 0)
	{
		is_sorted(get()->head_a);
		size = list_size(get()->head_a);
		while (size > 0)
		{
			if (!(get()->head_a->value & (1 << bit)))
				pb();
			else
				ra();
			size--;
		}
		while (get()->head_b)
			pa();
		bit++;
		round--;
	}
}
