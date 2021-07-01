/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:01:22 by youncho           #+#    #+#             */
/*   Updated: 2021/07/02 07:24:36 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


#include <stdio.h>
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
		return ;
	}
	if (!i)
	{
		i = 8;
		c = *(++str);
		if (!c)
			exit(0);
	}
	usleep(50);
	if (c >> --i & 0x01)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}
/*
void	send_msg(char *str, pid_t server_pid)
{
	ft_putstr_fd("send bytes : ", 1);
	ft_putnbr_fd(ft_strlen(str) + 1, 1);
	ft_putchar_fd('\n', 1);
	while (*str)
	{
		//send_char(*str, server_pid);
		str++;
	}
	//send_char('\n', server_pid);
}
*/
void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	recv_bytes = 0;

	(void)siginfo;
	(void)unused;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\rrecv bytes : ", 1);
		ft_putnbr_fd(++recv_bytes, 1);
	}
	send_bit(0, 0);
}

int		main(int argc, char **argv)
{
	struct sigaction	e;
	pid_t				server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage : ./client [Server PID] [Msg]", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (!(100 <= server_pid && server_pid <= 99998))
	{
		ft_putstr_fd("Invalid [Server PID]", 1);
		return (1);
	}
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	send_bit(argv[2], server_pid);
	send_bit(0, 0);
	while (1)
		pause();
	return (0);
}
