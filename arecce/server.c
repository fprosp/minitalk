/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:07:33 by arecce            #+#    #+#             */
/*   Updated: 2022/06/17 17:46:05 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *a)
{
	static unsigned char	c;
	static unsigned int		i;
	pid_t					send_pid;

	send_pid = info->si_pid;
	c |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &c, 1);
		if (c == '\n')
			kill(send_pid, SIGUSR1);
		c = 0;
	}
	else
		c = c << 1;
	(void)a;
}

int	main(void)
{
	struct sigaction	ft_sig;

	ft_sig.sa_sigaction = sig_handler;
	ft_sig.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\nWaiting...\n", getpid());
	sigaction(SIGUSR1, &ft_sig, 0);
	sigaction(SIGUSR2, &ft_sig, 0);
	while (1)
		pause();
	return (0);
}
