/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:49:04 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/03 18:41:15 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i] && count == i)
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (i > 0 && (count == ft_strlen(s1) - 1 - i))
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				count++;
			j++;
		}
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	start;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = ft_start(s1, set);
	len = 0;
	if (start != ft_strlen(s1))
		len = ft_strlen(s1) - (start + ft_end(s1, set));
	str = malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
