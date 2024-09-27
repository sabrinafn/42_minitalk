/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:17 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/24 20:25:16 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	i;
	static char c;
	int	 bit;

	printf("c = [%d]\n", c);
//	printf("sig = [%d] and its binary = [%d]\n", sig, sig >> i);
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
		
	c = c + (bit << i);
	
//	printf("c = c + (sig << i) = [%c] = [%d]\n", c, c);
//	printf("*i = %d\n", i);
	
	if (i == 7)
	{
		printf("i = 7\n");
		printf("CHAR RETURNED: %c\n", c);
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
	printf("[server pid = %d]\n", server_pid);
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = NULL;
	action.sa_flags = 0;
	action.sa_handler = signal_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while (1)
	{
		pause();
	}
	return (0);
}
