/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:01:16 by youncho           #+#    #+#             */
/*   Updated: 2021/07/02 07:17:47 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char	c = 0x00;
	static int				cnt = 0;
	(void)unused;
	if (sig == SIGUSR1)
		c |= 0x01;
	if (++cnt == 8)
	{
		ft_putchar_fd(c , 1);
		c = 0x00;
		cnt = 0;
		kill(siginfo->si_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int		main(void)
{
	struct sigaction	e;

	ft_putstr_fd("Server PID [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	while (1)
		pause();
	return (0);
}
