/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:17 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/27 15:47:39 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *client, void *param)
{
	static int	i;
	static char	c;
	int			bit;

	(void)param;
	bit = 0;
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	c = c + (bit << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				server_pid;

	server_pid = getpid();
	ft_putstr_fd("server pid: [", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putstr_fd("]\n", 1);
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
