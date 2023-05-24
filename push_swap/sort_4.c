/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:45:19 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/24 15:50:08 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_4(void)
{
	int pos;
	static int flag;

	is_sorted(get()->head_a);
	while (flag < 1)
	{
		pos = find_pos(flag);
		if (pos <= 2)
		{
			while(get()->head_a->value != flag)
				ra();
			pb();
			flag++;
		}
		else if(pos >= 3)
		{
			while(get()->head_a && get()->head_a->value != flag)
			{
				rra();
				print_list(get()->head_a);
			}
			pb();
			flag++;
		}
	}
	sort_3();
	pa();
}
