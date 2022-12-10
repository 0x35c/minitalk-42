/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:36:50 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/03 17:31:03 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	if (!len || start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	while (len - start > ft_strlen(s))
		len--;
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
