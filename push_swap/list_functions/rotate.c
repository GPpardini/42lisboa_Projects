/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:30:45 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/18 19:08:32 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_node **head)
{
	t_node *current;
	t_node *temp;

	temp = *head;
	current = (*head)->next;
	*head = current;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
}