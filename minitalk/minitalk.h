/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:55:49 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/06 17:29:28 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	signal_handler(int signal, siginfo_t *sig, void *s);
void	bit_send(char c, int pid);
void	signal_cut(int signal);
int		ft_atoi(const char *str);
int		ft_strlen(char *string);
char	*ft_itoa(int num);


#endif
