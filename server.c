#include "minitalk.h"

void	sig_handler(int sig)
{
	printf("sig = %d\n", sig);
}

int	main(void)
{
	struct sigaction action;
	action.sa_handler = sig_handler;
	sigset_t	set;

	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaddset(&set, SIGUSR1);
	//sigaddset(&set, SIGUSR2);
	
	sigaction(SIGUSR1, &action, NULL);
	
	return (0);
}
