/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:05:56 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/09 19:06:06 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	is_rep(int num, t_node *stack_a)
{
	while (stack_a != NULL)
	{
		if (num == stack_a->value)
			free_exit(1);
		stack_a = stack_a->next;
	}
}
