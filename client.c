#include "minitalk.h"

void	sig_to_server(int pid, char	*str)
{
	int	j;
	int	bit;
	
	j = 0;
	while (str[j])
	{
		bit = 0;
		while (bit < 8)
		{
			if (str[j] >> (7 - bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep (50);
		}
		j++;
	}
	while (bit < 8)
	{
		kill(pid, SIGUSR2);
		bit++;
	}
}

int	main(int argc, char** argv)
{
	int	i;
	int	server_pid;
	
	i = 0;
	server_pid = 0;
	if (argc != 3)
		return (1);
	while (argv[1][i])
	{
		server_pid *= 10;
		server_pid += (argv[1][i] - '0');
		i++;
	}
	sig_to_server(server_pid, argv[2]);
	return (0);
}
