/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:30:55 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/22 17:06:04 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_node **head)
{
	t_node *temp;
	t_node *current;

	current = *head;
	temp = *head;
	(*head) = current->next;
	current = current->next;
	temp->next = current->next;
	current->next = temp;
	write(1, "sa\n", 3);
}