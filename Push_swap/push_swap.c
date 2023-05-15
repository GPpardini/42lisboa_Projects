/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:17:13 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/08 11:53:53 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} t_node;

t_node	*start_list(int value)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	head->value = value;
	head->next = NULL;
	return (head);
}

void	print_list(t_node *header)
{
	t_node *current;

	current = header;
	while(current->next != 0)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("%d\n", current->value);
}

void	add_new(t_node *header, int value)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	if(!new)
		return ;
	while(header->next != 0)
		header = header->next;
	header->next = new;
	new->value = value;
	new->next = NULL;
}

void	swap_two(t_node **header)
{
	t_node *temp;
	t_node *current;

	current = *header;
	temp = *header;
	(*header) = current->next;
	current = current->next;
	temp->next = current->next;
	current->next = temp;
}

void	first_to_end(t_node **header)
{
	t_node *current;
	t_node *temp;

	temp = *header;
	current = (*header)->next;
	*header = current;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
}

void	end_to_first(t_node **header)
{
	t_node *last;
	t_node *p_last;

	last = (*header)->next;
	p_last = *header;
	while (last->next != NULL)
	{
		p_last = p_last->next;
		last = last->next;
	}
	last->next = *header;
	*header = p_last->next;
	p_last->next = NULL;
}

int main (void)
{
	int i;
	t_node *header;

	i = 2;
	header = start_list(1);
	while (i <= 10)
	{
		add_new(header, i);
		i++;
	}
	printf("primeira lista feita:\n");
	print_list(header);
	//trocar o 1 e o segundo elemento da lista.
	printf("SWAP os primeiros dois elementos da lista:\n");
	swap_two(&header);
	print_list(header);
	printf("SWAP denovo dos primeiros dois elementos da lista:\n");
	swap_two(&header);
	print_list(header);
	printf("LOOP de 5 elementos para o FINAL da lista:\n");
	i = 0;
	while (i < 5)
	{
		first_to_end(&header);
		i++;
	}
	print_list(header);
	printf("LOOP de 5 elementos para o COMEÇO da lista:\n");
	i = 0;
	while (i < 5)
	{
		end_to_first(&header);
		i++;
	}
	print_list(header);
	return (0);
}
