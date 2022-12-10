/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:54:10 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/27 12:07:24 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_basecheck(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	size;
	unsigned int	number;

	number = nb;
	size = ft_strlen(base);
	if (size <= 1 || !ft_basecheck(base))
		return ;
	else if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		number *= -1;
	}
	if (number < size)
		ft_putchar(base[number % size], 1);
	else
	{
		ft_putnbr_base((number / size), base);
		ft_putnbr_base((number % size), base);
	}
}
