/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:22:27 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/18 20:29:35 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*start_list(int value)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	head->value = value;
	head->next = NULL;
	return (head);
}

void	print_list(t_node *head)
{
	t_node *current;

	current = head;
	while(current->next != 0)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("%d\n", (current->value));
}

void	add_new(t_node *head, int value)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	if(!new)
		return ;
	while(head->next != 0)
		head = head->next;
	head->next = new;
	new->value = value;
	new->next = NULL;
}

// t_stack *stack_a(void)
// {
// 	static t_stack stack;

// 	return(&stack)
// }