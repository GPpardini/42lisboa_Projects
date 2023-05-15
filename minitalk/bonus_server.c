/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:45:29 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/06 17:45:45 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *sig, void *s)
{
	(void)s;
	static int c;
	static int bits;
	static int zero_count;

	if (signal == SIGUSR1)
		c |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
			zero_count++;
		if (zero_count >= 2)
		{
			kill(sig->si_pid, SIGUSR2);
			zero_count = 0;
		}
		bits = 0;
		c = 0;
	}
	kill(sig->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	struct sigaction sig;
	(void)argv;
	(void)argc;
	char *pid;

	pid = ft_itoa(getpid());
	sig.sa_sigaction = (void *)signal_handler;
	sig.sa_flags = SA_SIGINFO;
	write(1, "starting server...\n", 19);
	write(1, "server PID: ", 12);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	write(1, "waiting for the client\n", 23);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return(0);
}
