/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:34:31 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/22 19:07:02 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_smallest(void)
{
	t_node* c;
	int num;

	c = get()->head_a;
	num = c->value;
	while (c->next != 0)
	{
		if (num > c->next->value)
			num = c->next->value;
		c = c->next;
	}
	return(num);
}

void	sort_5(void)
{
	int min;
	int flag;

	flag = 0;
	min = find_smallest();
	is_sorted(get()->head_a);
	printf("sort_5\n");
	while (flag < 2)
	(
		if (get()->head_a->value == min)
		{
			push(&get()->head_a, &get()->head_b);
			min = find_smallest();
			flag++;	
		}
		else
		{
			rotate(&get()->head_a);
		}
	)
	sort_3();
	push(&get()->head_b, &get()->head_a);
	push(&get()->head_b, &get()->head_a);
}
