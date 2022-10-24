/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:43 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/24 18:52:41 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_char_serv(char c, pid_t pid)
{
	unsigned char	bit;

	bit = 0b00000000;
	while (bit <= 128)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		bit <<= 1;
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
	ft_printf("Not a signal\n");
	i = 0;
	while (av[2][i])
	{
		if (!send_char_serv(av[2][i], pid))
			return (1);
		i++;
	}
	ft_printf("Not a signal\n");
	return (0);
}
