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

void bin_handler()
{
    
}

int main(void)
{
    struct sigaction    sig_act;

    sig_act.sa_flags = SA_SIGINFO;
    sig_act.sa_sigaction = bin_handler;
    ft_printf("Process IDentifier, known as PID: %d\n", getpid());
    sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
    while (1)
        pause();
    return (0);
}