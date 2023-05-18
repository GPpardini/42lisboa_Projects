/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:18:05 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/18 20:30:24 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int value;
	struct node *next;
} t_node;

t_node*    start_stack(char *argv[]);
void	add_new(t_node *head, int value);
void	print_list(t_node *head);
t_node	*start_list(int value);
static void    push(t_node *src, t_node *dest);
void	rev_rotate(t_node **head);
void	rotate(t_node **head);
void	swap(t_node **head);
int	ft_atoi(const char *str);
int	m_str(char const *s, char **split, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
