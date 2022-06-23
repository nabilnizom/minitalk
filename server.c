#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void signal_handler(int sig)
{
	static int 	bits = 0;
	static char	c = 0;
	
	c |= (sig == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		c = 0;
		bits = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	int	server_pid;
	
	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
		pause();
	return(0);
}
