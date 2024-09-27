/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:17 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/25 20:08:34 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *client, void *param)
{
	static int	i;
	static char c;
	int	 bit;
//	pid_t	client_pid = client->si_pid;

	(void)param;
	bit = 0;
	if (sig == SIGUSR1)
	{
		bit = 0;
		kill(client->si_pid, SIGUSR1);	
	}
	else if (sig == SIGUSR2)
	{
		bit = 1;
		kill(client->si_pid, SIGUSR1);	
	}
//	else
//		kill(client->si_pid, SIGUSR2);
	c = c + (bit << i);
	if (i == 7)
	{
	
		write(1, &c, 1);
		// printf("client pid = [%d]\n", client_pid); commented out, but it's working
		// it's printing the client's pid.
		i = 0;
		c = 0;
	}
	else
		i++;
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	action;
	
	server_pid = getpid();
	ft_putstr_fd("server pid: [", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putstr_fd("]\n", 1);
	action.sa_sigaction = signal_handler;//NULL;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;//0;
	//action.sa_handler = signal_handler; removing this to initiate sa_sigaction to signal_handler
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while (1)
	{
		pause();
	}
	return (0);
}
