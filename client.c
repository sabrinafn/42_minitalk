/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:08:36 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/23 21:03:10 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// create a function to check if the signal was received by the server
/*
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
}*/

void	send_bits(pid_t pid, char c)
{
	static int	i;
	int			bit;

	bit = 0;
	//printf("c >> i = [%d]\n", c >> i);
	bit = (c >> i) & 1;
	//printf("i = %d & bit = %d\n", i, bit);
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	i++;
	if (i == 8)
	{
	//	printf("___ 8 bits sent ___\n");
		usleep(4200);
		i = 0;
	}
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
	pid_t	pid = ft_atoi(av[1]);
	printf("pid = %d\n", pid);
	send_to_server(pid, av[2]);
//	signal(SIGUSR1, sighandler);
//	signal(SIGUSR2, sighandler);
	
	return 0;
}
