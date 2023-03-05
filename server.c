/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:37:06 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/01 18:36:46 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_handler(int sig, siginfo_t *info, void *a)
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

int main(void)
{
    struct sigaction    sig_act;

    sig_act.sa_sigaction = bin_handler;
    sig_act.sa_flags = SA_SIGINFO;
    ft_printf("Process IDentifier, known as PID: %d\n \
Wainting message... ",getpid());
    sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
    while (1)
        pause();
    return (0);
}