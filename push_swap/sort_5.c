/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:34:31 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/23 20:18:02 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


			
void	sort_5(void)
{
	int pos;
	static int flag;

	is_sorted(get()->head_a);
	printf("sort_5\n");
	while (flag < 2)
	{
		pos = find_pos(flag);
		if (pos <= 3)
		{
			while(get()->head_a->value != flag)
				ra();
			pb();
			flag++;
		}
		else if(pos >= 4)
		{
			while(get()->head_a && get()->head_a->value != flag)
				rra();
			pb();
			flag++;
		}
	}
	sort_3();
	pa();
	pa();
}
