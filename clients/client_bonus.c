/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:10:41 by youncho           #+#    #+#             */
/*   Updated: 2021/07/05 23:51:01 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	connection_terminate(pid_t server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(50);
		kill(server_pid, SIGUSR2);
	}
	exit(0);
}

void	send_bit(char *s, pid_t pid)
{
	static int				i = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			server_pid;

	if (s)
	{
		str = s;
		server_pid = pid;
		c = *str;
	}
	if (!i)
	{
		i = 8;
		c = *(++str);
		if (!c)
			connection_terminate(server_pid);
	}
	if (c && c >> --i & 0x01)
		kill(server_pid, SIGUSR1);
	else if (c)
		kill(server_pid, SIGUSR2);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	recv_bytes = 0;

	(void)siginfo;
	(void)unused;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\rReceive Acks : ", 1);
		ft_putnbr_fd(++recv_bytes, 1);
	}
	send_bit(0, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	e;

	if (argc != 3 || !(100 <= ft_atoi(argv[1]) && ft_atoi(argv[1]) <= 99998))
	{
		ft_putstr_fd("Usage : ./client [99 < Server PID < 99999] [Message]", 1);
		return (1);
	}
	if (!ft_strlen(argv[2]))
		exit(0);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	ft_putstr_fd("Send Bytes   : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	send_bit(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
