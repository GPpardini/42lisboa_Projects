/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:17:13 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/22 17:05:07 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_info* get(void)
{
	static t_info get;

	return(&get);
}

t_node*	start_stack_a(char *argv[])
{
	t_node* head;
	char**  num;
	int	 i;
	int	 y;
		
	head = NULL;
	i = 0;
	y = 0;
	while (argv[++i] != 0)
	{
		num = ft_split(argv[i], ' ');  
		if (num[y] != NULL && head == NULL)
			head = start_list(check_errors(num[y++], head));
		while  (num[y] != NULL)
		{
			if(head && num[y])
				add_new(head, check_errors(num[y++], head));
		}
		y = 0;
	}
	return(head);
}

int	check_errors(char* num, t_node *head)
{
	int i;
	char* test;
		
	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) || ((num[i] == '+' || num[i] == '-') && i != 0))
		   exit(11);
		i++;
	}
	test = ft_itoa(ft_atoi(num));
	if (ft_strcmp(test, num) != 0)
		exit(22);
	free(test);
	is_rep(ft_atoi(num), head);
	return (ft_atoi(num));
}

void	is_rep(int num, t_node *stack_a)
{
	while (stack_a != NULL)
	{
		if (num == stack_a->value)
			exit(42);
		stack_a = stack_a->next;
	}
}

int main (int argc, char* argv[])
{		
	if (argc < 2)
		exit(0);
	get()->head_a = start_stack_a(argv);
	printf("lista antes do sort:\n");
	print_list(get()->head_a);
	sort_3();
	printf("lista depois do sort:\n");
	print_list(get()->head_a);
	return (0);
}
