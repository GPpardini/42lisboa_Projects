/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:06:04 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/23 20:17:40 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    pa(void)
{
	t_node* temp;
	
	if (get()->head_b->next == NULL)
	{
		temp = get()->head_a;
		get()->head_a = get()->head_b;
		get()->head_a->next = temp;
		get()->head_b = NULL;
	}
	else
	{
		temp = get()->head_a;
		get()->head_a = get()->head_b;
		get()->head_b = get()->head_b->next;
		get()->head_a->next = temp;
	}
	write(1, "pa\n", 3);
}

void    pb(void)
{
	t_node* temp;
	
	if(!get()->head_b)
	{
		get()->head_b = get()->head_a;
		get()->head_a = get()->head_a->next;
		get()->head_b->next = NULL;
	}
	else
	{
		temp = get()->head_b;
		get()->head_b = get()->head_a;
		get()->head_a = get()->head_a->next;
		get()->head_b->next = temp;
	}
	write(1, "pb\n", 3);
}

