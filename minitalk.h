/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:28:07 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/25 10:42:54 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_str_compose
{
	char	c;
	int		pos;
	int		nb_bit;
}	t_str_compose;

#endif
