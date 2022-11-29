/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:43 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/28 10:29:56 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_pid_server(pid_t pid_server, pid_t pid_client)
{
	pid_t	bit;

	bit = 0b1000000000000000000000000000000;
	while (bit)
	{
		if (bit & pid_client)
		{
			if (kill(pid_server, SIGUSR1) == -1)
				return (0);
		}
		else
			if (kill(pid_server, SIGUSR2) == -1)
				return (0);
		bit >>= 1;
		usleep(10);
	}
	return (1);
}

void	sig_received(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("\e[5m\x1b[38;2;153;255;204mBit received!\n\x1b[0m\e[0m");
}

int	send_char_serv(char c, pid_t pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		bit >>= 1;
		if (c)
			pause();
		else
			usleep(10);
	}
	return (1);
}

int	main(int ac, char **av)
{
	pid_t	pid_server;
	int		i;

	(void)ac;
	pid_server = ft_atoi(av[1]);
	if (!send_pid_server(pid_server, getpid()))
		return (1);
	signal(SIGUSR1, sig_received);
	i = 0;
	while (av[2][i])
	{
		if (!send_char_serv(av[2][i], pid_server))
			return (1);
		i++;
	}
	if (!send_char_serv('\0', pid_server))
		return (1);
	return (0);
}
