/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:08:46 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/01 21:28:15 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(void)
{
	t_node	*c;

	c = get()->head_a;
	if (c->value < c->next->value && c->next->value > c->next->next->value && c->value < c->next->next->value)
	{
		rra();
		sa();
	}
	else if (c->value < c->next->value && c->next->value > c->next->next->value && c->value > c->next->next->value)
		rra();
	else if (c->value > c->next->value && c->next->value < c->next->next->value && c->value < c->next->next->value)
		sa();
	else if (c->value > c->next->value && c->next->value < c->next->next->value && c->value > c->next->next->value)
		ra();
	else if (c->value > c->next->value && c->next->value > c->next->next->value && c->value > c->next->next->value)
	{
		ra();
		sa();
	}
}
