/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:58:43 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/01 21:36:40 by gpardini         ###   ########.fr       */
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

void	add_new(t_node *head, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	while (head->next != 0)
		head = head->next;
	head->next = new;
	new->value = value;
	new->next = NULL;
}

void	free_list(t_node *list)
{
	t_node	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

int	list_size(t_node *head)
{
	t_node	*current;
	int		size;

	current = head;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
