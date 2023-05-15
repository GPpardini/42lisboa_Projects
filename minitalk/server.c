/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:17:40 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/13 19:22:53 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	get_char(int signal, int *creturn)
{
	static int c;
	static int bits;

	if (signal == SIGUSR1)
		c |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		*creturn = c;
		bits = 0;
		c = 0;
		return(1);
	}
	return (0);
}

int	get_lenght(int signal, int *lenght)
{
	static int c;
	static int bits;

	if (signal == SIGUSR1)
		c |= (0x01 << bits);
	bits++;
	if (bits == 32)
	{
		*lenght = c;
		bits = 0;
		c = 0;
		return(1);
	}
	return (0);
}

void	signal_handler(int signal, siginfo_t *sig, void *s)
{
	(void)s;
	int c;
	static int i;
	static int lenght;
	static int round;
	static char* string;

	if (round < 32)
		get_lenght(signal, &lenght);
	if (round == 31)
	{
		string = (char *)malloc(sizeof(char) * lenght);
		string[lenght - 1] = '\0';
	}
	if (round > 31)
	{
		if (1 == get_char(signal, &c))
		{
			string[i] = c;
			i++;
			lenght--;
		}
	}
	if ((round > 31) && (lenght == 1))
	{
		write(1, string, ft_strlen(string));
		lenght = 0;
		i = 0;
		round = -1;
		kill(sig->si_pid, SIGUSR2);
		free(string);
		string = NULL;
	}
	round++;
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



