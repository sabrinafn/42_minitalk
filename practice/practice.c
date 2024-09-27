#include "minitalk.h"

int x = 100;

void	signal_handler(int sig)
{
	x += 5;
	printf("x = %d\n", x);
	(void)sig;
}

int	main(void)
{
	pid_t	sig;

	signal(SIGUSR1, signal_handler);

	sig = fork(); // another process being created.
	// parent-child relationship between the two processes
	printf("[fork: %d]\n", sig);
	// this printf prints the value(???) of each process.
	// idk why but the parent will have a bigger value and
	// the child process created will start from 0.
	// so if fork is 0, it means that the child process was created???

	if (sig == 0) // in child process
	{
		pid_t parent = getppid();
		kill(parent, SIGUSR1);
		sleep(1);
		printf("Child says x=%d\n", x);	
		return (0);	
	}
	else // in parent process
	{
		int stat;
		wait(&stat);
	}
	// SIGUSR1 and SIGUSR2: almost the same thing apart
	// from the signal number.
	
	//kill(value, SIGUSR1);
	//kill(value, SIGUSR2);
	return (0);
}
