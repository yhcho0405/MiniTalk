/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:10:44 by youncho           #+#    #+#             */
/*   Updated: 2021/07/06 00:40:59 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char	c = 0x00;
	static int				cnt = 0;
	static pid_t			client_pid = 0;

	(void)unused;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++cnt == 8)
	{
		cnt = 0;
		if (c == 0x00)
		{
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0x00;
		kill(client_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(client_pid, SIGUSR2);
	}
}

int	main(void)
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
