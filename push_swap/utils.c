/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:22:27 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/24 18:58:55 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_exit(int flag)
{
	free_list(get()->head_a);
	free_list(get()->head_b);
	if (flag == 1)
		write(1, "ERROR\n", 6);
	else
		write(1, "sorted\n", 7);
	exit(0);
}

void	is_sorted(t_node *head)
{
	while (head->next != 0)
	{
		if (head->value > head->next->value)
			return ;
		head = head->next;
	}
	print_list(get()->head_a);
	free_exit(0);
}

int	num_wins(int num)
{
	t_node	*c;
	int		flag;

	c = get()->head_a;
	flag = 0;
	while (c->next != 0)
	{
		if (num > (c->value))
			flag++;
		c = c->next;
	}
	if (num > c->value)
		flag++;
	return (flag);
}

void	value_treat(void)
{
	t_node	*current;
	t_node	*new;

	current = get()->head_a;
	new = start_list(num_wins(current->value));
	current = current->next;
	while (current != NULL)
	{
		add_new(new, num_wins(current->value));
		current = current->next;
	}
	free_list(get()->head_a);
	get()->head_a = new;
}

int	find_pos(int num)
{
	t_node	*c;
	int		flag;

	flag = 1;
	c = get()->head_a;
	while (c)
	{
		if (num == c->value)
			return (flag);
		c = c->next;
		flag++;
	}
	return (num);
}
