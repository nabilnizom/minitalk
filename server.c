/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohd-ni <amohd-ni@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:49:33 by amohd-ni          #+#    #+#             */
/*   Updated: 2022/06/23 17:49:36 by amohd-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	static int	bits = 0;
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
	ft_printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
