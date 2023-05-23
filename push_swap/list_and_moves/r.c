/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:30:45 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/23 20:17:46 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(void)
{
	t_node* temp;
	t_node* current;
	
	temp = get()->head_a;
	current = get()->head_a->next;
	get()->head_a = get()->head_a->next;
	temp->next = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	write(1, "ra\n", 3);
}

void	rb(void)
{
	t_node* temp;
	t_node* current;
	
	temp = get()->head_b;
	current = get()->head_b->next;
	get()->head_b = get()->head_b->next;
	temp->next = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	write(1, "rb\n", 3);
}
