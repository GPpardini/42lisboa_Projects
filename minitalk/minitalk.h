/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:55:49 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/16 20:15:33 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	signal_handler(int signal, siginfo_t *sig, void *s);
void	signal_reset(int *round, int *i, siginfo_t *sig);
void	lenght_send(int c, int pid);
int		get_lenght(int signal, int *lenght);
void	bit_send(char c, int pid);
void	signal_cut(int signal);
int		get_char(int signal, int *creturn);
int		ft_atoi(const char *str);
int		ft_strlen(char *string);
char	*ft_itoa(int num);

#endif