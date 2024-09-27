/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:08:36 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/27 12:17:51 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(pid_t pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(4200);
		i++;
	}
}

void	send_to_server(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bits(pid, str[i]);
		i++;
	}
	send_bits(pid, '\0');
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
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("[E X I T]\n", 1);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;
	pid_t				server_pid;

	if (ac != 3)
	{
		ft_putstr_fd("ERROR\nUse: ./program PID STRING\n", 2);
		return (0);
	}
	if (!is_validpid(av[1]))
	{
		ft_putstr_fd("ERROR\nInvalid PID\n", 2);
		return (0);
	}
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	server_pid = ft_atoi(av[1]);
	send_to_server(server_pid, av[2]);
	while (1)
	{
		pause();
	}
	return (0);
}
