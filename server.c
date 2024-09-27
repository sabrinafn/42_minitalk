/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:17 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/21 20:44:34 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	printf("sig = %d\n", sig);
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
	sigset_t	set;
	struct sigaction	action;
	
	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaddset(&set, SIGUSR1);
	//sigaddset(&set, SIGUSR2);
	
	sigaction(SIGUSR1, &action, NULL);
	
	return (0);
}
