/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:13:58 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/13 16:43:29 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_send(char c, int pid)
{
	int		bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x001 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(5000000);
	}
}

2 | 1 

0000 0100

1000 1000
0001 0000
void	lenght_send(int c, int pid)
{
	int		bit;

	bit = 0;
	while (bit < 32)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(5000000);
	}
}

void	signal_cut(int signal)
{
	if (signal == SIGUSR2)
		write(1, "mensage received by the server\n", 31);
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	struct sigaction	sig;

	if (argc != 3)
		return (0);
	sig.sa_sigaction = (void *)signal_cut;
	sig.sa_flags = SA_SIGINFO;
	pid = ft_atoi(argv[1]);
	i = 0;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	lenght_send(ft_strlen(argv[2]), pid);
	while (argv[2][i] != '\0')
	{
		bit_send(argv[2][i], pid);
		i++;
	}
	return (0);
}
