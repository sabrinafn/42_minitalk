#include "minitalk.h"

int	main(void)
{
	printf("server\n");
	pid_t	value = getpid();
	printf("[PID: %d]\n", value);

	// SIGUSR1 and SIGUSR2: almost the same thing apart
	// from the signal number.
	
	//kill(value, SIGUSR1);
	kill(value, SIGUSR2);
	return (0);
}
