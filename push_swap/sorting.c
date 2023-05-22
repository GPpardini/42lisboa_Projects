/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:08:46 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/22 18:02:10 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	is_sorted(t_node* head)
{
	while (head->next != 0)
	{
		if (head->value > head->next->value)
			return ;
		head = head->next;
	}
	exit(13);
}

void	sort_3(void)
{
	t_node* c;
	
	is_sorted(get()->head_a);
	printf("sort_3\n");
	c = get()->head_a;
	if (c->value < c->next->value && c->next->value > c->next->next->value && c->value < c->next->next->value)
	{
		rev_rotate(&get()->head_a);
		swap(&get()->head_a);
	}
	else if (c->value < c->next->value && c->next->value > c->next->next->value && c->value > c->next->next->value)
		rev_rotate(&get()->head_a);
	else if (c->value > c->next->value && c->next->value < c->next->next->value && c->value < c->next->next->value)
		swap(&get()->head_a);
	else if (c->value > c->next->value && c->next->value < c->next->next->value && c->value > c->next->next->value)
		rotate(&get()->head_a);
	else if (c->value > c->next->value && c->next->value > c->next->next->value && c->value > c->next->next->value)
	{
		rotate(&get()->head_a);
		swap(&get()->head_a);
	}
}
