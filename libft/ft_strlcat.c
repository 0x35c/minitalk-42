/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:35:19 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/03 19:25:27 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;

	i = 0;
	lendest = 0;
	lensrc = ft_strlen(src);
	if (!size)
		return (lensrc);
	while (dst[lendest] && lendest < size)
		lendest++;
	if (dst[lendest])
		return (lensrc + size);
	while (src[i] && (lendest + i + 1) < size)
	{
		dst[lendest + i] = src[i];
		i++;
	}
	dst[lendest + i] = 0;
	return (lendest + lensrc);
}
