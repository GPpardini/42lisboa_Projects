/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:30:55 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/24 18:41:59 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(void)
{
	t_node	*temp;

	temp = get()->head_a;
	get()->head_a = get()->head_a->next;
	temp->next = get()->head_a->next;
	get()->head_a->next = temp;
	write(1, "sa\n", 3);
}

void	sb(void)
{
	t_node	*temp;

	temp = get()->head_b;
	get()->head_b = get()->head_b->next;
	temp->next = get()->head_b->next;
	get()->head_b->next = temp;
	write(1, "sb\n", 3);
}
