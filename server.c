/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:53 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/27 12:02:38 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_joiner	g_server;

void	receive_client_pid(int sig)
{
	if (sig == SIGUSR1)
		g_server.pid += g_server.pid_bit;
	g_server.pid_bit >>= 1;
}

void	handler_sig(int sig)
{
	if (sig == SIGUSR1)
		g_server.c += g_server.c_bit;
	g_server.c_bit >>= 1;
	if (g_server.nb_bit == 8)
	{
		g_server.str = ft_strjoin_c(g_server.str, g_server.c);
		if (g_server.c == 0)
		{
			ft_printf("%s", g_server.str);
			free(g_server.str);
			g_server.str = NULL;
		}
		g_server.c = 0;
		g_server.c_bit = 0b10000000;
		g_server.nb_bit = 1;
	}
	else
		g_server.nb_bit++;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	g_server.pid = 0;
	g_server.pid_bit = 0b10000000000000000000000000000000;
	g_server.nb_bit = 1;
	g_server.c = 0;
	g_server.str = NULL;
	g_server.c_bit = 0b10000000;
	signal(SIGUSR1, handler_sig);
	signal(SIGUSR2, handler_sig);
	while (1)
		;
	return (0);
}
