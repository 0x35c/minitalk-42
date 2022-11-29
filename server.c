/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:53 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/28 10:24:41 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_joiner	g_server = {'p', 0, 0, NULL, 0b10000000,
	0b1000000000000000000000000000000, 1};

void	receive_client_pid(int signum)
{
	if (signum == SIGUSR1)
		g_server.pid += g_server.pid_bit;
	g_server.pid_bit >>= 1;
	g_server.nb_bit++;
}

void	receive_char(int signum)
{
	if (signum == SIGUSR1)
		g_server.c += g_server.c_bit;
	g_server.c_bit >>= 1;
	if (g_server.nb_bit == 8)
	{
		g_server.str = ft_strjoin_c(g_server.str, g_server.c);
		if (g_server.c == 0)
		{
			ft_printf("%s", g_server.str);
			if (g_server.str)
				free(g_server.str);
			g_server.str = NULL;
			g_server.flag = 'p';
			g_server.nb_bit = 1;
			g_server.pid = 0;
			g_server.pid_bit = 0b1000000000000000000000000000000;
			return ;
		}
		g_server.c = 0;
		g_server.c_bit = 0b10000000;
		g_server.nb_bit = 1;
	}
	else
		g_server.nb_bit++;
	kill(g_server.pid, SIGUSR1);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (1)
	{
		if (g_server.flag == 'p')
		{
			signal(SIGUSR1, receive_client_pid);
			signal(SIGUSR2, receive_client_pid);
		}
		else if (g_server.flag == 'c')
		{
			signal(SIGUSR1, receive_char);
			signal(SIGUSR2, receive_char);
		}
		if (g_server.nb_bit == 32 && g_server.pid)
		{
			g_server.nb_bit = 1;
			g_server.c_bit = 0b10000000;
			g_server.flag = 'c';
			signal(SIGUSR1, receive_char);
			signal(SIGUSR2, receive_char);
		}
	}
	return (0);
}
