/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:08:36 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/21 19:20:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int c)
{
	printf("signal: %d\n", c);
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
