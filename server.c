/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:17 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/23 17:16:33 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void	handle_sigusr1(int sig)
{
	// update the its value is now 0
	// ??
}

void	handle_sigusr2(int sig)
{
	// update the its value is now 1
	// ??
}
*/
void	signal_handler(int sig)
{
	static int	i;
	static char c;

	printf("sig = %d\n", sig);
	i = 0;
	c = 0;
	
	c = c + (sig << i);
	if (i == 7)
	{
		printf("%c", c);
		i = 0;
		c = 0;
	}
}

// there will be a function which will send back to the client >>
// like a response, that the signal was received and >>
// the action was performed
// maybe after every 8 bits received, transformed into decimal >>
// then transformed into chars and printed, it will send this signal >>
// that everything is cool and keep sending more signals to it

// function to convert from each binary digit to a decimal >>
// which then will be calculated and printed as a char once it its 8 bits

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	action;
	
	server_pid = getpid();
	printf("[server pid = %d]\n", server_pid);
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while (1)
		pause();
	return (0);
}
