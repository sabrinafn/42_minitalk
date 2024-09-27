#include "minitalk.h"

void	signal_handler(int sig)
{
	int	x;

	x = 5;
	printf("x = %d\n", x);
	(void)sig;
}

int	main(void)
{
	printf("server\n");
	pid_t	value = getpid();
	pid_t	two;
	printf("[first PID: %d]\n", value);

	signal(SIGUSR1, signal_handler);

	two = fork();

	if (two == 0)
	{
		pid_t parent = getppid();
		kill(parent, SIGUSR1);
		sleep(1);
	
	
	}
	else
	{
		init stat;
		wait(&stat);
	}
	// SIGUSR1 and SIGUSR2: almost the same thing apart
	// from the signal number.
	
	//kill(value, SIGUSR1);
	//kill(value, SIGUSR2);
	return (0);
}
