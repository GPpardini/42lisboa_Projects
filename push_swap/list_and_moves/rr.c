/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:30:20 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/24 19:09:02 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra(void)
{
	t_node	*last;
	t_node	*prev;
	t_node	*temp;

	if (!get()->head_a)
		return ;
	temp = get()->head_a;
	last = get()->head_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	get()->head_a = last;
	last->next = temp;
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(void)
{
	t_node	*last;
	t_node	*prev;
	t_node	*temp;

	if (!get()->head_b)
		return ;
	temp = get()->head_b;
	last = get()->head_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	get()->head_b = last;
	last->next = temp;
	prev->next = NULL;
	write(1, "rra\n", 4);
}
