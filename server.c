/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:53 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/24 18:56:35 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_compose	g_bit;

void	handler_sig1(int sig)
{
	if (sig)
	{
		g_bit.c += g_bit.pos;
		g_bit.pos <<= 1;
	}
}

void	handler_sig2(int sig)
{
	if (sig)
		g_bit.pos <<= 1;
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;
	pid_t				pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	pause();
	act1.sa_handler = handler_sig1;
	sigaction(SIGUSR1, &act1, NULL);
	act2.sa_handler = handler_sig2;
	sigaction(SIGUSR2, &act2, NULL);
	ft_printf("%c", g_bit.c);
	return (0);
}
