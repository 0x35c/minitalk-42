/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:31:01 by ulayus            #+#    #+#             */
/*   Updated: 2022/09/30 14:36:10 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cast1;
	const unsigned char	*cast2;

	cast1 = (const unsigned char *) s1;
	cast2 = (const unsigned char *) s2;
	i = 0;
	if (!n)
		return (0);
	while (i + 1 < n && cast1[i] == cast2[i])
		i++;
	return (cast1[i] - cast2[i]);
}
