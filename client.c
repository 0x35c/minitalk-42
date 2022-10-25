/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:43 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/25 00:11:10 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_char_serv(char c, pid_t pid)
{
	unsigned char	bit;

	bit = 0b00000001;
	while (bit <= 128 && bit > 0)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		bit <<= 1;
		usleep(1000);
	}
	return (1);
}

int main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	ft_printf("Starting to send signals...\n");
	i = 0;
	while (av[2][i])
	{
		if (!send_char_serv(av[2][i], pid))
			return (1);
		i++;
	}
	ft_printf("Signals sent !\n");
	return (0);
}
