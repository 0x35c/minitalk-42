/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:15:01 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/05 10:14:04 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_abs(long int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

static int	nb_digits(int n)
{
	int	count;

	count = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (!n)
		return (ft_strdup("0"));
	if (n > 0)
		i = nb_digits(n);
	else
		i = nb_digits(n) + 1;
	str = malloc(i + 1);
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[i--] = 0;
	while ((i >= 0 && n > 0) || (i >= 1 && n < 0))
	{
		str[i--] = ft_abs((long int)n) % 10 + 48;
		n = n / 10;
	}
	return (str);
}
