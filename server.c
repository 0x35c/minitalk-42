/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:53 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/25 11:26:32 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_str_compose	g_bit;

void	handler_sig1(int sig)
{
	//ft_printf("SIGUSR1 - Start\n");
	if (sig)
	{
		//ft_printf("Pos: %d\n", g_bit.pos);
		g_bit.c += g_bit.pos;
		//ft_printf("Pos: %d, binary char: %d\n", g_bit.pos, g_bit.c);
		g_bit.pos <<= 1;
	}
	if (g_bit.nb_bit == 8 && g_bit.c)
	{
		//ft_printf("Check 2, nb_bit: %d\n", g_bit.nb_bit);
		//ft_printf("Char: %d -> %c\n", g_bit.c, g_bit.c);
		ft_printf("%c", g_bit.c);
		g_bit.c = 0;
		g_bit.pos = 1;
		g_bit.nb_bit = 1;
	}
	else
	{
		g_bit.nb_bit++;
		//ft_printf("Check 1, nb_bit: %d, char: %c\n", g_bit.nb_bit, g_bit.c);
	}
	//ft_printf("SIGUSR1 - End\n");
	//ft_printf("\n");
}

void	handler_sig2(int sig)
{
	//ft_printf("SIGUSR2 - Start\n");
	if (sig)
	{
		//ft_printf("Pos: %d\n", g_bit.pos);
		g_bit.pos <<= 1;
		//ft_printf("Pos: %d, binary char: %d\n", g_bit.pos, g_bit.c);
	}
	if (g_bit.nb_bit == 8)
	{
		//ft_printf("Check 2, nb_bit: %d\n", g_bit.nb_bit);
		//ft_printf("Char: %d -> %c\n", g_bit.c, g_bit.c);
		ft_printf("%c", g_bit.c);
		g_bit.c = 0;
		g_bit.pos = 1;
		g_bit.nb_bit = 1;
	}
	else
	{
		g_bit.nb_bit++;
		//ft_printf("Check 1, nb_bit: %d, char: %c\n", g_bit.nb_bit, g_bit.c);
	}
	//ft_printf("SIGUSR2 - End\n");
	//ft_printf("\n");
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;
	pid_t				pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	g_bit.c = 0;
	g_bit.nb_bit = 1;
	g_bit.pos = 1;	
	act1.sa_handler = handler_sig1;
	sigaction(SIGUSR1, &act1, NULL);
	act2.sa_handler = handler_sig2;
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
	{
	}
	return (0);
}
