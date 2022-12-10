/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:08:12 by ulayus            #+#    #+#             */
/*   Updated: 2022/09/30 19:11:26 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*cast1;
	unsigned char	*cast2;

	cast1 = (unsigned char *) s1;
	cast2 = (unsigned char *) s2;
	i = 0;
	if (!n)
		return (0);
	while (i + 1 < n && cast1[i] == cast2[i] && cast1[i])
		i++;
	return (cast1[i] - cast2[i]);
}
