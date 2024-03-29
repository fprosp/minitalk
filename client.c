/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:37:09 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/06 15:30:58 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_received(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Messaggio ricevuto\n");
	return ;
}

void	bit_dispatcher(int pid, char *str)
{
	char	c;
	int		i;
	int		nbit;

	i = 0;
	while (str[i] != '\0')
	{
		nbit = 7;
		c = str[i];
		while (nbit >= 0)
		{
			if (c >> nbit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			--nbit;
		}
		++i;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || ft_atoi(argv[1]) <= 0)
	{
		ft_printf("Wrong, correct use of program would be: \
./client [VALID PID] [STRING TO SEND]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, msg_received);
	bit_dispatcher(pid, argv[2]);
	usleep (300);
	return (0);
}
