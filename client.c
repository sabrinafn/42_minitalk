/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:08:36 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/21 20:41:06 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int c)
{
	printf("signal: %d\n", c);
}

// create a function to check if the signal was received by the server

void	function_to_convert_char_tobinary()
{
	// it will be receiving a char at a time >
	// it will be converting to binary >
	// and sending each 0 and 1 as signals using >
	// SIGUSR1 and SIGUSR2
	
}

void	function_to_send_char_to_convert(char *str)
{
	// loop through whole array >
	// send each char to function convert_char_and set one bit at a time >
	// keep looping untill all chars have been sent
}

int	main(int ac, char **av)
{
	printf("[pid = %d]\n", getpid());
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
//	printf("SIGUSR1 = %d\n", SIGUSR1);
	while (1)
	{
		printf("-\n");
		pause();
	}
	return 0;
}	
