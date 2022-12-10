/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:45:11 by ulayus            #+#    #+#             */
/*   Updated: 2022/09/30 14:55:17 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cast1;
	const unsigned char	*cast2;

	if ((!dest && !src) && n)
		return (0);
	cast1 = (unsigned char *) dest;
	cast2 = (unsigned const char *) src;
	i = 0;
	while (i < n)
	{
		cast1[i] = cast2[i];
		i++;
	}	
	return (cast1);
}
