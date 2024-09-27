/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:08:36 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/24 19:47:40 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// create a function to check if the signal was received by the server

void	send_bits(pid_t pid, char c)
{
	static int	i;
	int			bit;

	//printf("c >> i = [%d]\n", c >> i);
	bit = (c >> i) & 1;
	//printf("i = %d & bit = %d\n", i, bit);
	if (bit == 0)
	{
		printf("CLIENT: %d\n", bit);
		kill(pid, SIGUSR1);
	}
	else if (bit == 1)
	{
		printf("CLIENT: %d\n", bit);
		kill(pid, SIGUSR2);
	}
	usleep(4200);
	if (i == 7)
	{
		printf("___ 8 bits sent ___\n");
		i = 0;
	}
	else
		i++;
}

void	send_char(pid_t pid, char c)
{
	int i = 0;

	printf("send_char function\n");
	while (i < 8)
	{
		send_bits(pid, c);
		i++;
	}
}

void	send_to_server(pid_t pid, char *str)
{
	int	i = 0;
	printf("send_to_server function\n");
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
	if (sig == 0)
		printf("sig == 0\n");
	if (sig < 0)
		printf("sig < 0\n");
	if (sig > 0)
		printf("sig > 0\n");
	exit(0);
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
/*	struct sigaction action;

	sigemptyset(&action.sa_mask);
	action.sa_sigaction = NULL;
	action.sa_flags = 0;
	action.sa_handler = signal_handler;
*/	pid_t	pid = ft_atoi(av[1]);
	printf("pid = %d\n", pid);
	send_to_server(pid, av[2]);

//	sigaction(SIGUSR1, &action, NULL);	
	
	return 0;
}
