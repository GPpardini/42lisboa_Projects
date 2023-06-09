/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:18:05 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/13 16:59:16 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			value;
	struct node	*next;
}	t_node;

typedef struct info
{
	t_node	*head_a;
	t_node	*head_b;
	char **matrix;
}	t_info;

int		ft_atoi(const char *str);
int		ft_isdigit(int a);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_node	*start_list(int value);
void	add_new(t_node *head, int value);
void	free_list(t_node *list);
int		list_size(t_node *head);
void	sa(void);
void	sb(void);
void	pa(void);
void	pb(void);
void	ra(void);
void	rb(void);
void	rra(void);
void	rrb(void);
void	start_stack_a(char *argv[]);
t_info	*get(void);
int		check_errors(char *num, t_node*head);
void	is_rep(int num, t_node *stack_a);
void	sort_3(void);
void	sort_4(void);
void	sort_5(void);
void	sort_radix(void);
int		find_pos(int num);
void	value_treat(void);
void	is_sorted(t_node *head);
int		num_wins(int num);
void	free_exit(int flag);
void	free_matrix(char **matrix);
void	print_list(t_node *head); //so para testes apagar depois;

#endif
