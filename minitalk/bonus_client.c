/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:46:05 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/06 17:46:17 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_send(char c, int pid)
{
	int		bit;

	bit = 0;
	while (bit < 8)
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
		write(1, "mensage received by the server\n",  31);
}

int main (int argc, char *argv[])
{
	int pid;
	int i;

	if (argc != 3)
		return(0);
	struct sigaction sig;
	sig.sa_sigaction = (void *)signal_cut;
	sig.sa_flags = SA_SIGINFO;
	pid = ft_atoi(argv[1]);
	i = 0;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (argv[2][i] != '\0')
	{
		bit_send(argv[2][i], pid);
		i++;
	}
	bit_send('\0', pid);
	bit_send('\0', pid);
	return(0);
}
