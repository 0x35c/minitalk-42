/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:00:17 by ulayus            #+#    #+#             */
/*   Updated: 2022/09/30 19:46:21 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*cast1;
	char		*cast2;

	cast1 = (const char *) src;
	cast2 = (char *) dest;
	if ((!cast1 && !cast2) && n > 0)
		return (0);
	i = 0;
	if (&cast1[0] > &cast2[0])
	{
		while (i < n)
		{
			cast2[i] = cast1[i];
			i++;
		}
	}
	else
		while (n--)
			cast2[n] = cast1[n];
	return (cast2);
}
