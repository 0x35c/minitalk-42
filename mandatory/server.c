/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:53 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/10 15:01:39 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_joiner	g_server = {'p', 0, 0, NULL, 0b10000000,
	0b1000000000000000000000000000000, 1};

void	exit_free(char *str)
{
	if (str)
		free(str);
	exit(1);
}

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
			usleep(200);
			if (g_server.str != NULL)
				free(g_server.str);
			g_server.str = NULL;
			if (kill(g_server.pid, SIGUSR2) == -1)
				exit_free(g_server.str);
			init_handlers(PID);
			return ;
		}
		init_handlers(CHAR);
	}
	else
		g_server.nb_bit++;
	if (kill(g_server.pid, SIGUSR1) == -1)
		exit_free(g_server.str);
}

void	init_handlers(int flag)
{
	if (flag == PID)
	{
		signal(SIGUSR1, receive_client_pid);
		signal(SIGUSR2, receive_client_pid);
		g_server.nb_bit = 1;
		g_server.pid = 0;
		g_server.pid_bit = 0b1000000000000000000000000000000;
	}
	else if (flag == CHAR)
	{
		signal(SIGUSR1, receive_char);
		signal(SIGUSR2, receive_char);
		g_server.c = 0;
		g_server.c_bit = 0b10000000;
		g_server.nb_bit = 1;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	init_handlers(PID);
	while (1)
	{
		if (g_server.nb_bit == 32 && g_server.pid)
			init_handlers(CHAR);
	}
	return (0);
}
