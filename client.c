/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:37:09 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/01 18:48:07 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_received(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Messaggio ricevuto\n");
	return ;
}

void bit_dispatcher(int pid, char *str)
{
    int strlen;
    int i;
    int b;

    strlen = ft_strlen(str);
    i = 0;
    while (i < strlen)
    {
        b = 7;
		while (b >= 0)
		{
			if ((str[i] >> b) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			b--;
			usleep(100);
		}
		i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int pid;

    ft_printf("Use correct of program: \
            ./client [PID] [STRING TO SEND] ");
    if (argc != 3 || ft_atoi(argv[1]) < 0)
    {
        ft_printf("Invalid arguments, please reload");
        return (0);
    }
    pid = ft_atoi(argv[1]);
    signal(SIGUSR1, msg_received);
    bit_dispatcher(pid, argv[2]);
    usleep (300);
    return (0);
}