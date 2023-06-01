/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:17:13 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/01 14:27:38 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_info	*get(void)
{
	static t_info	get;

	return (&get);
}

void	is_rep(int num, t_node *stack_a)
{
	while (stack_a != NULL)
	{
		if (num == stack_a->value)
			free_exit(1);
		stack_a = stack_a->next;
	}
}

void	is_int(char *num)
{
	char	*max = "2147483647";
	char	*pmax = "+2147483647";
	char	*min = "-2147483648";

	int len;
	int flag;

	len = ft_strlen(num);
	if ((len > 11) || (len == 11 && (*num != '-' || *num != '+')))
		free_exit(1);
	if ((len == 10 && (*num == '-' || *num == '+')) || len < 10)
		return ;
	if (len == 11)
	{
		if (*num == '+')
			flag = ft_strcmp(num, pmax);
		if (*num == '-')
			flag = ft_strcmp(num, min);
	}
	if (len == 10)
		ft_strcmp(num, max);
	if (flag <= 0)
}

int	check_errors(char *num, t_node *head)
{
	int		i;
	char	*test;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			free_exit(1);
		i++;
	}
	free(test);
	is_rep(ft_atoi(num), head);
	return (ft_atoi(num));
}

t_node	*start_stack_a(char *argv[])
{
	t_node	*head;
	char	**num;
	int		i;
	int		y;

	head = NULL;
	i = 0;
	y = 0;
	while (argv[++i] != 0)
	{
		num = ft_split(argv[i], ' ');
		if (num[y] != NULL && head == NULL)
			head = start_list(check_errors(num[y++], head));
		while (num[y] != NULL)
		{
			if (head && num[y])
				add_new(head, check_errors(num[y++], head));
		}
		y = 0;
		free_matrix(num);
	}
	return (head);
}

int	main(int argc, char *argv[])
{
	int	lenght;

	if (argc < 2)
		free_exit(1);
	get()->head_a = start_stack_a(argv);
	value_treat();
	printf("lista value_treat:\n");
	print_list(get()->head_a);
	lenght = list_size(get()->head_a);
	is_sorted(get()->head_a);
	if (lenght == 2)
		sa();
	if (lenght == 3)
		sort_3();
	if (lenght == 4)
		sort_4();
	if (lenght == 5)
		sort_5();
	if (lenght > 5)
		sort_radix();
	is_sorted(get()->head_a);
	return (0);
}
