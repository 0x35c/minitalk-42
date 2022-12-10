/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:43 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/10 15:12:16 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		usleep(80);
	}
	return (1);
}

void	sig_received(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("\e[5m\x1b[38;2;153;255;204mMessage received!\n\x1b[0m\e[0m");
	else
		return ;
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
		usleep(200);
	}
	return (1);
}

int	main(int ac, char **av)
{
	pid_t	pid_server;
	int		i;

	if (ac != 3)
		return (1);
	pid_server = ft_atoi(av[1]);
	signal(SIGUSR2, sig_received);
	signal(SIGUSR1, sig_received);
	if (!send_pid_server(pid_server, getpid()))
		return (1);
	i = 0;
	while (av[2][i])
	{
		if (!send_char_serv(av[2][i], pid_server))
			return (1);
		i++;
	}
	if (!send_char_serv('\0', pid_server))
		return (1);
	usleep(200);
	return (0);
}
