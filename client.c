/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:08:36 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/25 20:34:41 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// create a function to check if the signal was received by the server

void	send_bits(pid_t pid, char c)
{
	static int	i;
	int			bit;

	bit = (c >> i) & 1;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	usleep(4200);
	if (i == 7)
		i = 0;
	else
		i++;
}

void	send_char(pid_t pid, char c)
{
	int i = 0;

	while (i < 8)
	{
		send_bits(pid, c);
		i++;
	}
}

void	send_to_server(pid_t pid, char *str)
{
	int	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
}

int	is_validpid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("SIGUSR1 returned\n", 1);
	}
	else
	{
		ft_putstr_fd("something else returned\n", 1);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("ERROR\nUse: ./program PID STRING\n");
		return (0);
	}
	if (!is_validpid(av[1]))
	{
		printf("ERROR\nInvalid PID\n");
		return (0);
	}
	pid_t client_pid = getpid();

	ft_putstr_fd("CLIENT: client pid: [", 1);
	ft_putnbr_fd(client_pid, 1);
	ft_putstr_fd("]\n", 1);
	
	struct sigaction action;

	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	
/************************************/	
	pid_t	pid = ft_atoi(av[1]);
	send_to_server(pid, av[2]);

	// send to server function has to receive siginfo_t
	// and it will be assigned to action.sa_sigaction
	while (1)
	{
		pause();
	}
	return 0;
}
