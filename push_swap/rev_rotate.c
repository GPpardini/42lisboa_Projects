/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:30:20 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/18 19:08:22 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rotate(t_node **head)
{
	t_node *last;
	t_node *p_last;

	last = (*head)->next;
	p_last = *head;
	while (last->next != NULL)
	{
		p_last = p_last->next;
		last = last->next;
	}
	last->next = *head;
	*head = p_last->next;
	p_last->next = NULL;
}