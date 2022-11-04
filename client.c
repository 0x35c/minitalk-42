/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:43 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/27 12:02:51 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_pid_server(pid_t pid_server, pid_t pid_client)
{
	pid_t bit;

	bit = 0b10000000000000000000000000000000

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
		usleep(100);
	}
	return (1);
}

int	send_char_serv(char c, pid_t pid_server)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(pid_server, SIGUSR1) == -1)
				return (0);
		}
		else
			if (kill(pid_server, SIGUSR2) == -1)
				return (0);
		bit >>= 1;
		pause();
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
	return (0);
}